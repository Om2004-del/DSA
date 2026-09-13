class Solution {
public:

    void dfs(vector<vector<int>>& grid, int r, int c) {

        int n = grid.size();        // rows
        int m = grid[0].size();     // columns

        if(r < 0 || r >= n ||
           c < 0 || c >= m ||
           grid[r][c] != 1) {
            return;
        }

        // Mark boundary-connected land as visited
        grid[r][c] = 0;

        dfs(grid, r - 1, c); // up
        dfs(grid, r + 1, c); // down
        dfs(grid, r, c - 1); // left
        dfs(grid, r, c + 1); // right
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Left and right borders
        for(int i = 0; i < n; i++) {

            if(grid[i][0] == 1)
                dfs(grid, i, 0);

            if(grid[i][m - 1] == 1)
                dfs(grid, i, m - 1);
        }

        // Top and bottom borders
        for(int j = 0; j < m; j++) {

            if(grid[0][j] == 1)
                dfs(grid, 0, j);

            if(grid[n - 1][j] == 1)
                dfs(grid, n - 1, j);
        }

        // Count remaining land
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};