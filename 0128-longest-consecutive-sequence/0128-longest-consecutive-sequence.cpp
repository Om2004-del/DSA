class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;

        for(int x : nums) {
            st.insert(x);
        }

        int maxLen = 0;

        for(int x : st) {

            // x is the starting point
            if(st.find(x - 1) == st.end()) {

                int current = x;
                int len = 1;

                while(st.find(current + 1) != st.end()) {
                    current++;
                    len++;
                }

                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};