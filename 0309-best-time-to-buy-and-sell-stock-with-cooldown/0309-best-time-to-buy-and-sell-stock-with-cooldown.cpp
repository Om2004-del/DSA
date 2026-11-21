class Solution {
public:
    int solve(int idx, int buy, vector<int>& prices,
              vector<vector<int>>& dp) {

        if (idx >= prices.size())
            return 0;

        if (dp[idx][buy] != -1)
            return dp[idx][buy];

        int profit = 0;

        if (buy == 1) {
            // Buy or Skip
            int take = -prices[idx] + solve(idx + 1, 0, prices, dp);
            int skip = solve(idx + 1, 1, prices, dp);

            profit = max(take, skip);
        }
        else {
            // Sell or Skip
            int take = prices[idx] + solve(idx + 2, 1, prices, dp);
            int skip = solve(idx + 1, 0, prices, dp);

            profit = max(take, skip);
        }

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, 1, prices, dp);
    }
};