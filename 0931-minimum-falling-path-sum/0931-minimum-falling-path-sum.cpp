class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>&dp ,vector<vector<bool>>&visited){
        int n = matrix.size();
        if(j<0 || j>=n) return 1e9;
        if(i==n-1) return matrix[i][j];
        if(visited[i][j]) return dp[i][j];
        visited[i][j] = true;

        int down = solve(i + 1, j, matrix, dp, visited);
        int downLeft = solve(i + 1, j - 1, matrix, dp, visited);
        int downRight = solve(i + 1, j + 1, matrix, dp, visited);
         return dp[i][j] = matrix[i][j] +
                          min({down, downLeft, downRight});

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        int ans = 1e9;
        for (int j = 0; j < n; j++) {
            ans = min(ans, solve(0, j, matrix, dp, visited));
        }

        return ans;
    }
};