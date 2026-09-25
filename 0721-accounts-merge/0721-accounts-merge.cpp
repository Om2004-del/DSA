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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        size.resize(n,1);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }
        //email->account index
        unordered_map<string,int>mp;
        //Step 1 : connect accounts having common email
        for(int i = 0 ; i < n ; i++){
            for(int j = 1 ; j < accounts[i].size() ; j++){
                string email = accounts[i][j];
                //email already belongs to another account
                if(mp.find(email) != mp.end()){
                    unionSet(i,mp[email]);
                }else{
                    mp[email] = i;
                }
            }
        }
        //step 2 : group emails according to their parent
        unordered_map<int , vector<string>>merged; 
        for(auto &it:mp){
            string email = it.first;
            int accountIndex = it.second;
            int root = find(accountIndex);
            merged[root].push_back(email);
        }
        //Step:3 create final ans

        vector<vector<string>>ans;
        for(auto &it:merged){
            int root = it.first;
            vector<string>emails = it.second;
            sort(emails.begin() ,emails.end());
            vector<string>temp; 
            //account name
            temp.push_back(accounts[root][0]);
            //emails
            for(string email:emails){
                temp.push_back(email);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};