class Solution {
public:
    int solve(int idx, int buy, int cap,
              vector<int>& prices,
              vector<vector<vector<int>>>& dp) {

        if (idx == prices.size() || cap == 0)
            return 0;

        if (dp[idx][buy][cap] != -1)
            return dp[idx][buy][cap];

        int profit = 0;

        if (buy == 1) {
            int take = -prices[idx] + solve(idx + 1, 0, cap, prices, dp);
            int skip = solve(idx + 1, 1, cap, prices, dp);

            profit = max(take, skip);
        }
        else {
            int take = prices[idx] + solve(idx + 1, 1, cap - 1, prices, dp);
            int skip = solve(idx + 1, 0, cap, prices, dp);

            profit = max(take, skip);
        }

        return dp[idx][buy][cap] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k + 1, -1))
        );

        return solve(0, 1, k, prices, dp);
    }
};