class Solution {
public:
    void solve(vector<int>&candidates, int i, int target, vector<int>&temp, vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i==candidates.size() || target <0){
            return;
        }
        temp.push_back(candidates[i]);
        solve(candidates,i,target-candidates[i],temp,ans);
        temp.pop_back();
        solve(candidates,i+1,target,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(candidates,0,target,temp,ans);
        return ans;
    }
};