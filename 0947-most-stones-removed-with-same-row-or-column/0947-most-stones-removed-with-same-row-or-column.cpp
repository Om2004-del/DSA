class Solution {
public:
    vector<int>parent,size;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unionSet(int u , int v){
        int pu = find(u);
        int pv = find(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv] +=size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];

        }    
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        size.resize(n,1);
        //initially every node is separate
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }
        //same rows or same columns
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1; j < n ; j ++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    unionSet(i,j);
                }
            }
        }
        int components = 0 ; 
        for(int i = 0 ; i < n ; i++){
            if(find(i)==i) components++;
        }
        return n-components;
    }
};