class Solution {
public:
    void solve(int start, int k, int target,
               vector<int>& temp,
               vector<vector<int>>& ans) {

        // Base case
        if (temp.size() == k) {
            if (target == 0) {
                ans.push_back(temp);
            }
            return;
        }

        // Try numbers from start to 9
        for (int i = start; i <= 9; i++) {

            // If number is greater than target,
            // no need to continue
            if (i > target)
                break;

            temp.push_back(i);

            solve(i + 1, k, target - i, temp, ans);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(1, k, n, temp, ans);

        return ans;
    }
};