class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto flight : flights){
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];
            adj[u].push_back({v,price});
        }

        vector<int>dist(n,INT_MAX);
        dist[src] = 0;

        queue<pair<int,int>>q;
        q.push({src,0});

        int stops = 0;
        while(!q.empty() && stops <= k){
            int size = q.size();
            vector<int>temp = dist;
            while(size--){
                auto it = q.front();
                q.pop();

                int node = it.first;
                int cost = it.second;

                for(auto edge : adj[node]){
                    int next = edge.first;
                    int price = edge.second;
                    if(cost + price < temp[next]){
                        temp[next] = cost + price;
                        q.push({next,temp[next]});
                    }
                }
            }
            dist = temp; 
            stops++;
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};