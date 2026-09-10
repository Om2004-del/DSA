class Solution {
public:
    int dfs(vector<vector<int>>&grid, int r, int c){
        if(r < 0 || r >= grid.size() || c < 0 || c >=grid[0].size() || grid[r][c]==0){
            return 0; 
        }
        grid[r][c] = 0; 
        int area = 1 ;
        
        area += dfs(grid,r-1,c);
        area += dfs(grid,r+1,c);
        area += dfs(grid,r,c-1);
        area += dfs(grid,r,c+1);
        return area; 
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0; 
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    int area = dfs(grid,i,j);
                    ans = max(ans,area);
                }
            }
        }
        return ans;
    }
};