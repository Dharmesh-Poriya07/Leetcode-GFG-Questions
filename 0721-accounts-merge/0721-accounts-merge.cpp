class Solution {
private:
    vector<int> parent;
    int find(int node){
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent = vector<int>(n);
        unordered_map<string,int> email2id;
        for(int i=0;i<n;i++){
            parent[i] = i;
            for(int j=1;j<accounts[i].size();j++){
                if(email2id.end() != email2id.find(accounts[i][j])){
                    parent[find(email2id[accounts[i][j]])] = find(i);
                }else{
                    email2id[accounts[i][j]] = parent[i];
                }
            }
        }
        
        unordered_map<int,vector<string>> newaccs;
        for(auto &e : email2id)
            newaccs[find(e.second)].push_back(e.first);
        
        vector<vector<string>> ans;
        for(auto &a : newaccs){
            auto &emails = a.second;
            sort(emails.begin(),emails.end());
            emails.insert(emails.begin(),accounts[a.first][0]);
            ans.emplace_back(emails);
        }
        return ans;
    }
};