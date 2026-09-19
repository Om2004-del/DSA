class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        //build graph
        for(auto road : roads){
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);

         priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0 ; 
        ways[0] = 1; 
        pq.push({0,0});
        int MOD = 1e9+7;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            long long d = it.first;
            int node = it.second;
            //ignore outdated entry
            if(d > dist[node]) continue; 

            for(auto edge : adj[node]){
                int next = edge.first;
                int wt = edge.second;
                long long newDist = d+wt;

                //found a shorter path
                if(newDist < dist[next]){
                    dist[next] = newDist;
                    ways[next] = ways[node];
                    pq.push({newDist,next});
                }
                else if(newDist == dist[next]){
                    ways[next] = (ways[next] + ways[node]) % MOD;
                }
            }

        }
        return ways[n-1];
    }
};