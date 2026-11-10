class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
        int n = s1.size();
        int m = s2.size();
        //first string finished
        if(i==n){
            int sum =0;
            for(int k=j; k<m; k++){
                sum +=s2[k];
            }
            return sum;
        }
        //second string finished
        if(j==m){
            int sum=0;
            for(int k=i; k<n; k++){
                sum +=s1[k];
            }
            return sum;
        }
        if(dp[i][j] !=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            return dp[i][j] = solve(i+1,j+1,s1,s2,dp);
        }

        int delete1 = s1[i] + solve(i+1,j,s1,s2,dp);
        int delete2 = s2[j] + solve(i,j+1,s1,s2,dp);
        return dp[i][j] = min(delete1,delete2);
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,s1,s2,dp);
    }
};