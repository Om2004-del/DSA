class Solution {
public:
    int solve(int i, int j, string &s,
              vector<vector<int>>& dp) {

        // Empty substring
        if(i > j) return 0;

        // Single character
        if(i == j) return 1;

        // Already calculated
        if(dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if(s[i] == s[j]) {
            return dp[i][j] = 2 + solve(i+1, j-1, s, dp);
        }

        // Characters don't match
        return dp[i][j] = max(
            solve(i+1, j, s, dp),
            solve(i, j-1, s, dp)
        );
    }

    int longestPalindromeSubseq(string s) {

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n-1, s, dp);
    }
};