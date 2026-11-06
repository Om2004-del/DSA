class Solution {
public:
    /*int solve(int index, int prev, vector<int>&arr, int difference, vector<vector<int>>&dp){
        int n = arr.size();
        if(index==n) return 0;
        if(dp[index][prev+1] !=-1) return dp[index][prev+1];

        int notTake = solve(index+1, prev, arr, difference, dp);
        int take =0;
        if(prev==-1 || arr[index] - arr[prev] ==difference){
            take = 1 + solve(index+1, index, arr, difference, dp);
        }
        return dp[index][prev+1] = max(notTake, take);
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,arr,difference,dp);
    }*/
    int longestSubsequence(vector<int>&arr, int difference){
        unordered_map<int,int>dp;
        int maxi =0;
        for(int i=0; i<arr.size(); i++){
            int curr = arr[i];
            int prev = curr - difference;
            dp[curr] = dp[prev] +1;
            maxi = max(maxi,dp[curr]);
        }
        return maxi;
    }
};