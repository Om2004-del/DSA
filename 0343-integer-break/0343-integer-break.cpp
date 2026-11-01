class Solution {
public:
    int solve(int n, vector<int>&dp){
        if(n==1) return 1;
        if(dp[n] !=-1) return dp[n];
        int ans = 0;
        for(int i=1; i<n; i++){
            int notBreak = n-i;
            int breakFurther = solve(n-i,dp);
            int best = max(notBreak, breakFurther);
            ans = max(ans,i*best);
        }
        return dp[n] = ans;
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};