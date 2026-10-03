class Solution {
public:
    void solve(int n , string s , int open, int close , vector<string>&ans){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(open < n){
            solve(n,s + '(' , open+1,close,ans);
        }
        if(close < open){
            solve(n , s + ')' , open,close+1,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n,"",0,0,ans);
        return ans;
    }
};