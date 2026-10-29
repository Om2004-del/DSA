class Solution {
public:
    int dp[71][71][71];
    int solve(int i, int j1, int j2, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        if(j1<0 || j1>=n || j2<0 || j2>=n) return -1e9;
        if(dp[i][j1][j2] !=-1) return dp[i][j1][j2];

        if(i==m-1){
            if(j1==j2){
                return dp[i][j1][j2] = grid[i][j1];
            }
            return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
        }
        int cherries = grid[i][j1];
        if(j1!=j2){
            cherries+=grid[i][j2];
        }
        int maxi = INT_MIN;
        for(int d1 = -1 ; d1<=1; d1++){
            for(int d2 = -1; d2<=1; d2++){
                maxi = max(maxi,solve(i+1,j1+d1,j2+d2,grid));
            }
        }
        return dp[i][j1][j2] = maxi+cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n = grid[0].size();
        return solve(0,0,n-1,grid);
    }
};