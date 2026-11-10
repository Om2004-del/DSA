
class Solution {
public:
    bool solve(int i, int j, string &s, string &p) {

        int n = s.size();
        int m = p.size();

        if(j == m) return i == n;

        bool match = (i < n &&
                     (s[i] == p[j] || p[j] == '.'));

        if(j+1 < m && p[j+1] == '*') {

            // Zero occurrence
            bool skip = solve(i, j+2, s, p);

            // One or more occurrences
            bool take = match && solve(i+1, j, s, p);

            return skip || take;
        }

        return match && solve(i+1, j+1, s, p);
    }

    bool isMatch(string s, string p) {
        return solve(0, 0, s, p);
    }
};
