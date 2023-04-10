class Solution {
public:
    bool dfs(vector<int> adj[],int src, vector<bool> &vis, vector<bool> &pathVis, vector<bool> &ans){
        pathVis[src] = vis[src] = true;
        for(int negh : adj[src]){
            if(!vis[negh]){
                if(dfs(adj,negh,vis,pathVis,ans))
                    return true;
            }else if(pathVis[negh]){
                return true;
            }
        }
        ans[src] = true;
        pathVis[src] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        for(int u=0;u<n;u++){
            for(int v : graph[u]){
                adj[u].push_back(v);
            }
        }
        
        vector<bool> vis(n,false),pathVis(n,false),ans(n,false);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis,pathVis,ans);
            }
        }
        vector<int> safeNodes;
        for(int i=0;i<n;i++){
            if(ans[i])
                safeNodes.push_back(i);
        }
        return safeNodes;
    }
};
