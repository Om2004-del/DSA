
class Solution {
public:

    int solve(int index, int k, int n,
              vector<vector<int>>& cost,
              vector<vector<int>>& dp) {

        if(k == 1) {
            return cost[index][n-1];
        }

        if(dp[index][k] != -1) {
            return dp[index][k];
        }

        int mini = INT_MAX;

        for(int j = index; j <= n-k; j++) {

            int currCost = cost[index][j];

            int remainingCost =
                solve(j+1, k-1, n, cost, dp);

            mini = min(mini,
                       currCost + remainingCost);
        }

        return dp[index][k] = mini;
    }

    int palindromePartition(string s, int k) {

        int n = s.size();

        vector<vector<int>> cost(
            n, vector<int>(n, 0)
        );

        // Precompute palindrome conversion cost
        for(int i = n-1; i >= 0; i--) {

            for(int j = i+1; j < n; j++) {

                cost[i][j] = cost[i+1][j-1]
                           + (s[i] != s[j]);
            }
        }

        vector<vector<int>> dp(
            n, vector<int>(k+1, -1)
        );

        return solve(0, k, n, cost, dp);
    }
};
