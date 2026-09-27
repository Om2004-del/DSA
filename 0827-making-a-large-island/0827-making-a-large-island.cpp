class Solution {
public:
    vector<int> parent, size;
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void unionSet(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        parent.resize(n*n);
        size.resize(n*n,1);
        for(int i = 0 ; i < n*n ; i++){
            parent[i] = i;
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        //1. Connect all existing land cells
        for(int r = 0 ; r < n ; r++){
            for(int c = 0 ; c<n ; c++){
                if(grid[r][c]==0) continue;
                int node = r*n+c;
                for(int k = 0 ; k <4; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if(nr >=0 && nr < n && nc >=0 && nc < n && grid[nr][nc]==1){
                        int neighbour = nr*n+nc;
                        unionSet(node,neighbour);
                    }
                }
            }

        }
        int ans = 0 ; 
        //2. Check every water cell
        for(int r = 0 ; r < n ; r++){
            for(int c = 0 ; c <n ; c++){
                if(grid[r][c]==1) continue;
                set<int>components;
                for(int k = 0 ; k < 4 ; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if(nr >=0 && nr < n && nc >=0 && nc<n && grid[nr][nc]==1){
                        int neighbour = nr*n+nc;
                        components.insert(find(neighbour));
                    }
                }
                int currentSize =1;
                //add size of unique components
                for(int root : components){
                    currentSize += size[root];
                }
                ans = max(ans,currentSize);
            }
        }
        //edge case : grid already contains all 1's
        if(ans==0) return n*n;
        return ans;


    }
};