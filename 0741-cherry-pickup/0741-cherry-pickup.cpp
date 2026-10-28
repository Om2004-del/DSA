class Solution {
public:
    int solve(int r1, int c1, int r2,
              vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {

        int n = grid.size();
        const int NEG = -1000000000;

        // Person 2 ka column calculate karo
        int c2 = r1 + c1 - r2;

        // Check karo ki koi position grid ke bahar toh nahi
        if (r1 >= n || c1 >= n || r2 >= n ||
            c2 < 0 || c2 >= n) {
            return NEG;
        }

        // Thorn wali cell par nahi ja sakte
        if (grid[r1][c1] == -1 ||
            grid[r2][c2] == -1) {
            return NEG;
        }

        // Dono destination par pahunch gaye
        if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }

        // Agar state pehle calculate ho chuki hai
        if (dp[r1][c1][r2] != -1) {
            return dp[r1][c1][r2];
        }

        // Current cells ki cherries count karo
        int cherries = grid[r1][c1];

        // Same cell ho toh cherry ko dobara count nahi karna
        if (r1 != r2 || c1 != c2) {
            cherries += grid[r2][c2];
        }

        // Dono ke possible next moves
        int bothDown = solve(r1 + 1, c1, r2 + 1, grid, dp);

        int firstDown = solve(r1 + 1, c1, r2, grid, dp);

        int secondDown = solve(r1, c1 + 1, r2 + 1, grid, dp);

        int bothRight = solve(r1, c1 + 1, r2, grid, dp);

        // In chaar possibilities mein se maximum lo
        int best = max({bothDown, firstDown,
                        secondDown, bothRight});

        // Agar koi valid path hi nahi mila
        if (best == NEG) {
            return dp[r1][c1][r2] = NEG;
        }

        // Current cherries + future mein maximum cherries
        return dp[r1][c1][r2] = cherries + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();

        // -1 ka matlab: state abhi calculate nahi hui
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(
                n, vector<int>(n, -1)
            )
        );

        // Dono persons (0,0) se start karenge
        return max(0, solve(0, 0, 0, grid, dp));
    }
};