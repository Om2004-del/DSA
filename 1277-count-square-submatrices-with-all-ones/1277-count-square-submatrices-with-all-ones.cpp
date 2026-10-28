class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&matrix, vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(matrix[i][j]==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int left = solve(i,j-1,matrix,dp);
        int top = solve(i-1,j,matrix,dp);
        int diagonal = solve(i-1,j-1,matrix,dp);

        return dp[i][j] = 1+min({left,top,diagonal});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans +=solve(i,j,matrix,dp);
            }
        }
        return ans;
    }
};