class Solution {
public:
    bool solve(int i, int j, string &s,
               vector<vector<int>>& dp) {

        // Single character or empty substring
        if(i >= j) return true;

        // Already calculated
        if(dp[i][j] != -1)
            return dp[i][j];

        // First and last characters must match
        if(s[i] == s[j]) {
            return dp[i][j] = solve(i + 1, j - 1, s, dp);
        }

        return dp[i][j] = false;
    }

    int countSubstrings(string s) {

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int count = 0;

        for(int i = 0; i < n; i++) {

            for(int j = i; j < n; j++) {

                if(solve(i, j, s, dp)) {
                    count++;
                }
            }
        }

        return count;
    }
};



//expand around centre wala solution ...
/*class Solution {
public:
    int expand(string &s, int left, int right) {

        int count = 0;

        while(left >= 0 && right < s.size() &&
              s[left] == s[right]) {

            count++;

            left--;
            right++;
        }

        return count;
    }

    int countSubstrings(string s) {

        int n = s.size();
        int count = 0;

        for(int i = 0; i < n; i++) {

            // Odd length palindromes
            count += expand(s, i, i);

            // Even length palindromes
            count += expand(s, i, i + 1);
        }

        return count;
    }
};*/