
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        if(n == 0) return 0;

        // dp[i] = LIS length ending at index i
        vector<int> dp(n, 1);

        // count[i] = Number of LIS of length dp[i]
        vector<int> count(n, 1);

        // Calculate LIS length and count
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < i; j++) {

                if(nums[i] > nums[j]) {

                    // Case 1: Found a longer subsequence
                    if(dp[j] + 1 > dp[i]) {

                        dp[i] = dp[j] + 1;

                        // Copy the number of ways
                        count[i] = count[j];
                    }

                    // Case 2: Found another way of same length
                    else if(dp[j] + 1 == dp[i]) {

                        count[i] += count[j];
                    }
                }
            }
        }

        // Find the global maximum LIS length
        int maxLen = 0;

        for(int i = 0; i < n; i++) {
            maxLen = max(maxLen, dp[i]);
        }

        // Count all LIS having maximum length
        int ans = 0;

        for(int i = 0; i < n; i++) {

            if(dp[i] == maxLen) {
                ans += count[i];
            }
        }

        return ans;
    }
};
