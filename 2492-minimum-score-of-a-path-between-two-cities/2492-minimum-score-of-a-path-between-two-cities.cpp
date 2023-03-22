class Solution {
private:
    int mindist;
    void dfs(vector<vector<pair<int,int>>> &g,int n,int src,vector<bool> &vis){
        vis[src] = true;
        for(auto c : g[src]){
            mindist = min(mindist,c.second);
            if(!vis[c.first]){
                dfs(g,n,c.first,vis);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto r : roads){
            graph[r[0]].push_back({r[1],r[2]});
            graph[r[1]].push_back({r[0],r[2]});
        }
        vector<bool> vis(n+1,false);
        mindist = INT_MAX;
        dfs(graph,n,1,vis);
        return mindist;
    }
};