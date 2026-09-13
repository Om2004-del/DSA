class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single = 0;
        int twice = 0;

        for(int x : nums) {
            if(x < 10) {
                single += x;
            }
            else {
                twice += x;
            }
        }

        return single != twice;
    }
};