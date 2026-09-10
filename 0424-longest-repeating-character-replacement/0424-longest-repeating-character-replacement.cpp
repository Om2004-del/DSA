class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int left = 0; 
        int ans = 0; 
        int maxFreq = 0 ; 
        for(int right = 0 ; right < s.size(); right++){
            freq[s[right]-'A']++;
            maxFreq = max(maxFreq,freq[s[right]-'A']); 
            int windowSize = right-left+1; 
            int replacement = windowSize - maxFreq; 
            
            while(replacement >k){
                freq[s[left]-'A']--;
                left++; 

                windowSize = right-left+1;
                replacement = windowSize-maxFreq; 
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};