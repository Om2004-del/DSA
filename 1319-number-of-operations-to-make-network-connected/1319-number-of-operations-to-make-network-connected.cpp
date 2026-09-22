class Solution {
public:
    vector<int>parent,size;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void UnionSet(int u , int v){
        u = find(u);
        v = find(v);
        if(u==v) return ;
        if(size[u] < size[v]){
            parent[u] = v;
            size[v] += size[u];
        }else{
            parent[v] = u;
            size[u] += size[v];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        //not enough cables
        if(connections.size() < n-1) return -1;
        parent.resize(n);
        size.resize(n,1);
        for(int i = 0 ; i < n;i++){
            parent[i] = i;
        }
        //connect components
        for(auto &edges:connections){
            int u = edges[0];
            int v = edges[1];
            UnionSet(u,v);
        }
        int component = 0 ; 
        for(int i = 0 ; i < n ; i++){
            if(find(i)==i) component++;
        }
        return component-1;
    }
};