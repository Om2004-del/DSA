
/*class Solution {
public:

    int solve(int i, vector<vector<int>>& env,
              vector<int>& dp) {

        if (dp[i] != -1)
            return dp[i];

        int ans = 1;

        for (int j = 0; j < i; j++) {

            if (env[j][0] < env[i][0] &&
                env[j][1] < env[i][1]) {

                ans = max(ans, 1 + solve(j, env, dp));
            }
        }

        return dp[i] = ans;
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(), envelopes.end(),
             [](vector<int>& a, vector<int>& b) {

            if (a[0] == b[0])
                return a[1] > b[1];

            return a[0] < b[0];
        });

        int n = envelopes.size();

        vector<int> dp(n, -1);

        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, envelopes, dp));
        }

        return ans;
    }
};*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        // Sort width ascending, height descending
        sort(envelopes.begin(), envelopes.end(),
             [](vector<int>& a, vector<int>& b) {

            if (a[0] == b[0])
                return a[1] > b[1];

            return a[0] < b[0];
        });

        vector<int> temp;

        // Apply LIS on heights
        for (auto &env : envelopes) {

            int height = env[1];

            auto it = lower_bound(temp.begin(), temp.end(), height);

            if (it == temp.end()) {
                temp.push_back(height);
            }
            else {
                *it = height;
            }
        }

        return temp.size();
    }
};

