class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        int sum = 0 ; 
        int count = 0 ; 
        for(int x : nums){
            sum += x;
            int need = sum-goal;
            if(mp.find(need) != mp.end()){
                count += mp[need];
            }
            mp[sum
            ]++;
        }
        return count;
    }
};