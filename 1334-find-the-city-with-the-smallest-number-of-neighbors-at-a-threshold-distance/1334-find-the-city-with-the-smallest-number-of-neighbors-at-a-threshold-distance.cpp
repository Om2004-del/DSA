class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n, vector<int>(n,1e9));
        //distance from a city to itself = 0 
        for(int i = 0 ; i < n ; i++){
            dist[i][i] = 0 ;
        }
        //graph 
        for(auto e: edges){
            int u = e[0];
            int v = e[1]; 
            int wt = e[2];

            dist[u][v] = wt;
            dist[v][u] = wt;  
        }
         // Floyd Warshall
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
                }
            }
        }
        int ans = -1;
        int minCount = 1e9;
        //check every city 
        for(int i = 0 ; i < n ; i++){
            int count = 0 ; 
            for(int j = 0 ; j < n ; j++){
                if(dist[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count <=minCount){
                minCount = count; 
                ans = i;
            }
        }
        return ans;
    }
};