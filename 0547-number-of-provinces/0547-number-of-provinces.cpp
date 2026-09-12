class Solution {
public:
    void dfs(vector<vector<int>>& isConnected , int node , vector<bool>&visited){
        visited[node] = true;

        for(int neighbor = 0 ; neighbor < isConnected.size() ; neighbor++){
            if(!visited[neighbor] && isConnected[node][neighbor]==1){
                dfs(isConnected , neighbor , visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int  n = isConnected.size();
        vector<bool>visited(n,false);
        int cnt = 0 ; 
        for(int i = 0; i < n ; i++){
            if(!visited[i]){
                cnt++;
                dfs(isConnected, i , visited);
            }
        }
        return cnt;
    }
};