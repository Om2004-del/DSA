
class Solution {
public:
    int solve(int i, int j1, int j2,
              vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        // Check invalid column positions
        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
            return -1e9;

        // Return stored answer if already calculated
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        // Base case: last row
        if (i == m - 1) {
            if (j1 == j2)
                return dp[i][j1][j2] = grid[i][j1];

            return dp[i][j1][j2] =
                grid[i][j1] + grid[i][j2];
        }

        // Collect cherries from the current row
        int cherries = grid[i][j1];

        if (j1 != j2)
            cherries += grid[i][j2];

        int maxi = INT_MIN;

        // Try all 9 combinations of moves
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                int next = solve(i + 1,
                                 j1 + d1,
                                 j2 + d2,
                                 grid, dp);

                maxi = max(maxi, next);
            }
        }

        // Store and return the maximum cherries
        return dp[i][j1][j2] = cherries + maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Create and initialize 3D DP array
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(
                n, vector<int>(n, -1)
            )
        );

        // Start both robots from their initial positions
        return solve(0, 0, n - 1, grid, dp);
    }
};
