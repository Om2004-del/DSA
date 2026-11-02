class Solution {
public:
    const int MOD = 1e9+7;
    int solve(int n, int k, int target, vector<vector<int>>&dp){
        if(n==0 && target==0) return 1;
        if(n==0) return 0;
        if(target<0) return 0;
        if(dp[n][target] != -1) return dp[n][target];

        int ans =0;
        for(int face =1; face<=k; face++){
            ans = (ans+solve(n-1,k,target-face,dp)) % MOD;
        }
        return dp[n][target] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }
};