class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int n = numCourses;

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Create graph
        for (auto it : prerequisites) {

            int course = it[0];
            int prerequisite = it[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // Courses with 0 prerequisites
        for (int i = 0; i < n; i++) {

            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        // Kahn's Algorithm
        while (!q.empty()) {

            int course = q.front();
            q.pop();

            ans.push_back(course);

            for (auto next : adj[course]) {

                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // Cycle exists
        if (ans.size() != n) {
            return {};
        }

        return ans;
    }
};