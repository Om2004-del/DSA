class Solution {
public:
    int solve(int i, int j, string &s, vector<vector<int>>&dp){
        //empty substring or single charcter 
        if(i >=j) return 1;
        if(dp[i][j] != -1 ) return dp[i][j];
        
        if(s[i]==s[j]){
            return dp[i][j] = solve(i+1,j-1,s,dp);
        }
        return dp[i][j] =0;

    }
    string longestPalindrome(string s) {
        int n= s.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
        int maxLen = 0;
        int start =0;
        for(int i=0;i <n; i++){
            for(int j=i; j<n; j++){
                if(solve(i,j,s,dp)){
                    int len = j-i+1;

                    if(len > maxLen){
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};