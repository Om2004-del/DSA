class Solution {
public:
    int solve(int i, int target, vector<int>&nums, vector<vector<int>>&dp){
        if(i==nums.size()){
            return (target==0)?1:0;
        }
        if(dp[i][target] !=-1) return dp[i][target];
        int notTake = solve(i+1,target,nums,dp);
        int take = 0;
        if(nums[i]<=target){
            take = solve(i+1,target-nums[i],nums,dp);
        }
        return dp[i][target] = notTake+take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        for(int x: nums){
            sum+=x;
        }
        if(abs(target)>sum || (sum+target)%2==1) return 0;
        int subsetTarget = (sum+target)/2;
        vector<vector<int>>dp(n,vector<int>(subsetTarget+1,-1));
        return solve(0,subsetTarget,nums,dp);
    }
};