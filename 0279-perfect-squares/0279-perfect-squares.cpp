class Solution {
public:
    int solve(int i, int n, vector<int>&squares, vector<vector<int>>&dp){
        if(n==0) return 0;
        if(i==squares.size()) return 1e9;
        if(dp[i][n] !=-1) return dp[i][n];
        
        int notTake = solve(i+1,n,squares,dp);
        int take = 1e9;
        if(squares[i] <=n){
            take = 1 + solve(i,n-squares[i] , squares,dp);
        }
        return dp[i][n] = min(take,notTake);
    }
    int numSquares(int n) {
        vector<int>squares;
        for(int i=1; i*i<=n; i++){
            squares.push_back(i*i);
        }
        int m = squares.size();
        vector<vector<int>>dp(m,vector<int>(n+1,-1));
        int ans = solve(0,n,squares,dp);
        return ans >=1e9?-1:ans;

    }
};