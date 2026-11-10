class Solution {
public:
    int solve(int i, int j, string &a, string &b, vector<vector<int>>&dp){
        int n= a.size();
        int m = b.size();

        if(i==n) return m-j;
        if(j==m) return n-i;
        if(dp[i][j] != -1 ) return dp[i][j];
        //character match 
        if(a[i]==b[j]) return dp[i][j] = solve(i+1,j+1,a,b,dp);

        //insert
        int insert = 1 + solve(i,j+1,a,b,dp);
        //delete
        int del = 1 + solve(i+1,j,a,b,dp);
        //replace
        int replace = 1 + solve(i+1,j+1,a,b,dp);
        return dp[i][j] = min({insert,del,replace});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return solve(0,0,word1,word2,dp);
    }
};