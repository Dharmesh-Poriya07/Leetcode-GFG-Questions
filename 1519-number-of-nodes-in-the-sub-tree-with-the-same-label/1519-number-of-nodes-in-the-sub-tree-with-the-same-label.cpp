class Solution {
private:
    vector<int> ans;
    vector<bool> visited;
    vector<int> dfs(vector<vector<int>> &tree,int parent,string &labels){
        vector<int> freq(26,0);
        visited[parent] = true;
        for(auto &adj : tree[parent]){
            if(!visited[adj]){
                int i=0;
                for(auto &f : dfs(tree,adj,labels)) freq[i++]+=f;
            }
            
        }
        freq[labels[parent]-'a']++;
        ans[parent] = freq[labels[parent]-'a'];
        return freq;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans = vector<int>(n,0);
        visited = vector<bool>(n,false);
        vector<vector<int>> tree(n);
        for(auto &e : edges){
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        dfs(tree,0,labels);
        return ans;
    }
};