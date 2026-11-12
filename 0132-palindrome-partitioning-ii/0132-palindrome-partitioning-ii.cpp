
class Solution {
public:

    bool isPalindrome(string &s, int i, int j) {

        while(i < j) {
            if(s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    int solve(int index, string &s,
              vector<int> &dp) {

        int n = s.size();

        if(index == n)
            return 0;

        if(dp[index] != -1)
            return dp[index];

        int mini = INT_MAX;

        for(int j = index; j < n; j++) {

            if(isPalindrome(s, index, j)) {

                int cost = 1 + solve(j + 1, s, dp);

                mini = min(mini, cost);
            }
        }

        return dp[index] = mini;
    }

    int minCut(string s) {

        int n = s.size();

        vector<int> dp(n, -1);

        return solve(0, s, dp) - 1;
    }
};
