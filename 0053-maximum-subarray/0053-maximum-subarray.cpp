/*class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;
        for(int x: nums){
            currSum+=x;
            maxSum = max(maxSum,currSum);
            if(currSum <0){
                currSum=0;
            }
        }
        return maxSum;
    }
};*/

class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if (i == 0) {
            return nums[0];
        }

        // Return the saved answer if already calculated
        if (dp[i] != -1) {
            return dp[i];
        }

        int startNew = nums[i];
        int extend = solve(i - 1, nums, dp) + nums[i];

        return dp[i] = max(startNew, extend);
    }

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        int ans = nums[0];

        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, nums, dp));
        }

        return ans;
    }
};
