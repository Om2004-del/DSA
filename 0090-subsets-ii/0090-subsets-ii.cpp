class Solution {
public:
    void solve(vector<int>&nums, int start, vector<int>&temp, vector<vector<int>>&ans){
        ans.push_back(temp);
        for(int i = start; i<nums.size() ; i++){
            if(i>start && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(nums,i+1,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums,0,temp,ans);
        return ans;
    }
};