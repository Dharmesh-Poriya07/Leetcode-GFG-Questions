class Solution {
private:
    vector<int> sub,depth,sum;
    vector<vector<int>> g;
    int n;
    void dfs(int u,int par=-1){
        sub[u] = 1;
        for(auto x : g[u]){
            if(x==par) continue;
            depth[x] = depth[u]+1;
            dfs(x,u);
            sub[u] += sub[x];
        }
    }
    void dfs2(int u,int par=-1){
        for(auto x : g[u]){
            if(x==par) continue;
            sum[x] = sum[u]-sub[x]+(n-sub[x]);
            dfs2(x,u);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        sub.resize(n+1);
        depth.resize(n+1);
        sum.resize(n);
        g = vector<vector<int>>(n);
        for(auto e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(0);
        for(int i=0;i<n;i++){
            sum[0] += depth[i];
        }
        dfs2(0);
        return sum;
    }
};