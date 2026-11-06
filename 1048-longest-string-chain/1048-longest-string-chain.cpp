class Solution {
public:
    bool isPredecessor(string&a, string&b){
        if(b.size() != a.size() +1) return false;
        int i=0,j=0;
        while(i<a.size() && j < b.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        return i == a.size();
    }
    int solve(int i, vector<string>&words, vector<int>&dp){
        if(dp[i] !=-1) return dp[i];
        int maxi =1;
        for(int prev = 0; prev<i; prev++){
            if(isPredecessor(words[prev] , words[i])){
                maxi = max(maxi, 1+solve(prev,words,dp));
            }
        }
        return dp[i] = maxi;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin() , words.end(),[](string &a, string &b) { return a.size() < b.size();});
        vector<int>dp(n,-1);
        int maxi =1;
        for(int i=0; i<n; i++){
            maxi = max(maxi,solve(i,words,dp));
        }
        return maxi;
    }
};