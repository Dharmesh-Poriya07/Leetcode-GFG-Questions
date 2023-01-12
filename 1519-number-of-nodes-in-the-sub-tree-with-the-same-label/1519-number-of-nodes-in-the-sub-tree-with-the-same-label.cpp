class Solution {
private:
    vector<int> ans;
    vector<int> dfs(vector<vector<int>> &tree,int src,int parent,string &labels){
        vector<int> freq(26,0);
        for(auto &adj : tree[src]){
            if(adj == parent) continue;
            int i=0;
            for(auto &f : dfs(tree,adj,src,labels)) freq[i++]+=f;
        }
        freq[labels[src]-'a']++;
        ans[src] = freq[labels[src]-'a'];
        return freq;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans = vector<int>(n,0);
        vector<vector<int>> tree(n);
        for(auto &e : edges){
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        dfs(tree,0,-1,labels);
        return ans;
    }
};