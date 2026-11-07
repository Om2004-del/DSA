
class Solution {
public:

    int solve(int index, int diff, vector<int>& nums,
              vector<unordered_map<int, int>>& dp) {

        // Base case: no previous element
        if (index < 0) return 0;

        // Already calculated
        if (dp[index].find(diff) != dp[index].end()) {
            return dp[index][diff];
        }

        int ans = 0;

        // Find previous element having same difference
        for (int j = index - 1; j >= 0; j--) {

            if (nums[index] - nums[j] == diff) {

                ans = max(ans, 1 + solve(j, diff, nums, dp));
            }
        }

        return dp[index][diff] = ans;
    }

    int longestArithSeqLength(vector<int>& nums) {

        int n = nums.size();

        vector<unordered_map<int, int>> dp(n);

        int ans = 2;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                int diff = nums[j] - nums[i];

                // Current pair itself has length 2
                ans = max(ans, 2 + solve(i, diff, nums, dp));
            }
        }

        return ans;
    }
};
