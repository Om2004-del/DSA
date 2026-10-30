class Solution {
public:
    const int MOD = 1e9+7;
    int solve(int i, int members, int need, vector<int>&group, vector<int>&profit, vector<vector<vector<int>>>&dp){
        if(i==group.size()){
            return(need==0)?1:0;
        }
        if(dp[i][members][need] !=-1) return dp[i][members][need];
        int notTake = solve(i+1,members,need,group,profit,dp);
        int take =0;
        if(group[i] <=members){
            int newNeed = max(0,need-profit[i]);
            take = solve(i+1,members-group[i],newNeed,group,profit,dp);
        }
        return dp[i][members][need] = (take+notTake) %MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int l = group.size();
        vector<vector<vector<int>>>dp(l,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        return solve(0,n,minProfit,group,profit,dp);
    }
};