//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(vector<int> adj[],int src, vector<bool> &vis, vector<bool> &pathVis){
        pathVis[src] = vis[src] = true;
        for(int negh : adj[src]){
            if(!vis[negh]){
                if(dfs(adj,negh,vis,pathVis))
                    return true;
            }else if(pathVis[negh]){
                return true;
            }
        }
        pathVis[src] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V,false),pathVis(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj,i,vis,pathVis))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends