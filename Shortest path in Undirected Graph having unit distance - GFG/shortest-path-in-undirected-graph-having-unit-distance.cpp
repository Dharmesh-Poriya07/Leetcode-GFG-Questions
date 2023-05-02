//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> dis(N,INT_MAX);
        queue<int> q;
        vector<bool> vis(N,false);
        vis[src] = true;
        q.push(src);
        dis[src] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            
            for(int v : adj[u]){
                dis[v] = min(dis[v],dis[u]+1);
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        for(int i=0;i<N;i++){
            dis[i] = dis[i]==INT_MAX ? -1 : dis[i];
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends