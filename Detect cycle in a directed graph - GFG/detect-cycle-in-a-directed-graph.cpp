//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> ind(V,0);
        for(int u=0;u<V;u++){
            for(auto v : adj[u]){
                ind[v]++;
            }
        }
        
        queue<int> q;
        for(int u=0;u<V;u++){
            if(0==ind[u]){
                q.push(u);
            }
        }
        int count = 0;
        while(!q.empty()){
            auto u = q.front(); q.pop();
            count ++;
            for(auto v : adj[u]){
                ind[v]--;
                if(0==ind[v])
                    q.push(v);
            }
        }
        return ((count == V)?false:true);
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