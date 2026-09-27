class Solution {
public:
    vector<int>parent,size;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    void unionSet(int u , int v){
        int pu = find(u);
        int pv = find(v);
        if(pu==pv) return;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        parent.resize(n*n);
        size.resize(n*n,1);
        for(int i = 0 ; i < n*n ; i++){
            parent[i] = i;
        }
        vector<tuple<int,int,int>>cells;
        for(int r = 0 ; r < n ; r++){
            for(int c = 0 ; c < n ; c++){
                cells.push_back({grid[r][c] , r, c});
            }
        }
        //sort by height
        sort(cells.begin(),cells.end());
        vector<vector<int>>active(n,vector<int>(n,0));

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(auto[height,r,c] : cells){
            //activate current cell
            active[r][c] = 1;
            int node = r*n+c;
            for(int k = 0 ; k < 4;k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nr <n && nc>= 0 && nc <n && active[nr][nc]){
                    int neighbour = nr*n+nc;
                    unionSet(node,neighbour);
                }
            }
            int start = 0 ; 
            int end  = n*n-1;
            if(find(start) == find(end)){
                return height;
            }
        }
        return -1;

    }
};