class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        q.push({0,0});
        vis[0][0]=true;
        int r= 0 , c=0;
        while(!q.empty()){
            auto[x,y] = q.front();
            q.pop();
            r=x;
            c=y;
            int nr = x, nc = y;
            if(grid[x][y]=='L') nc--;
            else if(grid[x][y]=='D') nr++;
            else if(grid[x][y]=='U') nr--;
            else if(grid[x][y]=='R') nc++;

            if(nr<0 || nr >= m || nc < 0 || nc >=n) break;

            if(vis[nr][nc]) break;
            vis[nr][nc] = true;
            q.push({nr,nc});
        }
        return {r,c};
    }
};