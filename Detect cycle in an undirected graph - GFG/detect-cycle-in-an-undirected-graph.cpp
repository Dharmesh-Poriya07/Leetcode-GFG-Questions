//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool bfs(vector<int> adj[],vector<bool> &vis,int src){
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src] = true;
        while(!q.empty()){
            int u = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int v : adj[u]){
                if(!vis[v]){
                    vis[v] = true;
                    q.push({v,u});
                }else if(parent!=v){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i] and bfs(adj,vis,i)){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends