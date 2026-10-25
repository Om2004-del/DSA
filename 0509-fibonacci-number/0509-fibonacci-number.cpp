class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;

        // Step 1: Create DP array
        vector<int> dp(n + 1);

        // Step 2: Initialize base cases
        dp[0] = 0;
        dp[1] = 1;

        // Step 3: Calculate answers from bottom to top
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // Step 4: Return final answer
        return dp[n];
    }
};