
class Solution {
public:
    bool solve(int i, int j, string &s, string &p,
               vector<vector<int>>& dp) {

        if(i == 0 && j == 0) return true;

        if(j == 0) return false;

        if(i == 0) {
            for(int k = 0; k < j; k++) {
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s[i-1] == p[j-1] || p[j-1] == '?') {
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        }

        if(p[j-1] == '*') {

            bool empty = solve(i, j-1, s, p, dp);

            bool take = solve(i-1, j, s, p, dp);

            return dp[i][j] = (empty || take);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return solve(n, m, s, p, dp);
    }
};
