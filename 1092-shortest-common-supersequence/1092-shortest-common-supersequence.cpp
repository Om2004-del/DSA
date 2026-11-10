
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Step 1: Build LCS DP table
        for(int i = n-1; i >= 0; i--) {

            for(int j = m-1; j >= 0; j--) {

                if(str1[i] == str2[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        // Step 2: Construct SCS using DP table
        string ans = "";

        int i = 0, j = 0;

        while(i < n && j < m) {

            // Characters match
            if(str1[i] == str2[j]) {

                ans += str1[i];

                i++;
                j++;
            }

            // Take character from str1
            else if(dp[i+1][j] > dp[i][j+1]) {

                ans += str1[i];
                i++;
            }

            // Take character from str2
            else {

                ans += str2[j];
                j++;
            }
        }

        // Add remaining characters of str1
        while(i < n) {
            ans += str1[i];
            i++;
        }

        // Add remaining characters of str2
        while(j < m) {
            ans += str2[j];
            j++;
        }

        return ans;
    }
};
