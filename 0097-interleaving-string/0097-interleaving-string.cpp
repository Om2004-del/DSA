
class Solution {
public:

    bool solve(int i, int j, string &s1, string &s2,
               string &s3, vector<vector<int>>& dp) {

        int n = s1.size();
        int m = s2.size();

        // Both strings completely used
        if(i == n && j == m) {
            return true;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        bool take1 = false;
        bool take2 = false;

        // Take character from s1
        if(i < n && s1[i] == s3[i+j]) {
            take1 = solve(i+1, j, s1, s2, s3, dp);
        }

        // Take character from s2
        if(j < m && s2[j] == s3[i+j]) {
            take2 = solve(i, j+1, s1, s2, s3, dp);
        }

        return dp[i][j] = (take1 || take2);
    }

    bool isInterleave(string s1, string s2, string s3) {

        int n = s1.size();
        int m = s2.size();

        if(n + m != s3.size()) {
            return false;
        }

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return solve(0, 0, s1, s2, s3, dp);
    }
};
