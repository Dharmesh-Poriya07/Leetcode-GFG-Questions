class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        int province = 0;
        for(int i=0;i<n;i++){
            if(1&adj[i][i]){
                dfs(adj,i);
                province ++;
            }
        }
        return province;
    }
    void dfs(vector<vector<int>> &adj,int src){
        adj[src][src] = 0;
        auto adjs = adj[src];
        for(int i=0;i<adjs.size();i++){
            if(0!=adjs[i] && 1==adj[i][i]){
                dfs(adj,i);
            }
        }
    }
};