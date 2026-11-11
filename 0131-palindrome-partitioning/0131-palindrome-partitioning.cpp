
class Solution {
public:

    // Check whether substring is palindrome
    bool isPalindrome(string &s, int i, int j) {

        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    void solve(int index, string &s,
               vector<string> &path,
               vector<vector<string>> &ans) {

        // Entire string is processed
        if(index == s.size()) {
            ans.push_back(path);
            return;
        }

        // Try every possible ending index
        for(int j = index; j < s.size(); j++) {

            // Only choose palindrome substrings
            if(isPalindrome(s, index, j)) {

                // Take
                path.push_back(s.substr(index, j-index+1));

                // Explore remaining string
                solve(j + 1, s, path, ans);

                // Backtrack
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> path;

        solve(0, s, path, ans);

        return ans;
    }
};
