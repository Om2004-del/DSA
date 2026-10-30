class Solution {
public:
    int solve(int i, int m, int n, vector<string>&strs, vector<vector<vector<int>>>&dp){
        if(i==strs.size()) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];

        int zeroes=0,ones=0;
        for(char ch:strs[i]){
            if(ch=='0') zeroes++;
            else ones++;
        }
        int notTake = solve(i+1,m,n,strs,dp);
        int take =0;
        if(zeroes<=m && ones<=n){
            take = 1+solve(i+1,m-zeroes,n-ones,strs,dp);
        }
        return dp[i][m][n] = max(take,notTake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<vector<vector<int>>>dp(l,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,m,n,strs,dp);
    }
};