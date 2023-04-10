//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<bool> vis(V,false),pathVis(V,false),ans(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,i,vis,pathVis,ans);
            }
        }
        vector<int> safeNodes;
        for(int i=0;i<V;i++){
            if(ans[i])
                safeNodes.push_back(i);
        }
        return safeNodes;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends