class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        //build graph
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0; 
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        pq.push({0,k});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int node = it.second;

            for(auto edge : adj[node]){
                int next = edge.first;
                int wt = edge.second;
                if(d + wt < dist[next]){
                    dist[next] = d + wt;
                    pq.push({dist[next] , next});
                }
            }
        }
        int ans = 0 ;
        for(int i = 1 ; i <=n;i++){
            if(dist[i]==INT_MAX) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};