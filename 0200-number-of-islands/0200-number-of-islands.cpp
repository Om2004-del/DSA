class Solution {
public:

    void dfs(vector<vector<char>>& grid, int i, int j) {

        int rows = grid.size();
        int cols = grid[0].size();

        // Out of bounds
        if(i < 0 || i >= rows || j < 0 || j >= cols)
            return;

        // Water or already visited
        if(grid[i][j] == '0')
            return;

        // Mark as visited
        grid[i][j] = '0';

        // Go up
        dfs(grid, i - 1, j);

        // Go down
        dfs(grid, i + 1, j);

        // Go left
        dfs(grid, i, j - 1);

        // Go right
        dfs(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>>& grid) {

        int count = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(grid[i][j] == '1') {

                    // Found a new island
                    count++;

                    // Visit the complete island
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};