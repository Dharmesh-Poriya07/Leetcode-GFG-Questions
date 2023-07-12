class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        vector<int> ind(n,0), safeNodes;
        // reverse the edges and then apply topological sort 
        for(int u=0;u<n;u++){
            for(auto v : graph[u]){
                adj[v].push_back(u);
                ind[u]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(0==ind[i])
                q.push(i);
        }
        
        while(!q.empty()){
            auto u = q.front(); q.pop();
            safeNodes.push_back(u);
            
            for(int v : adj[u]){
                ind[v]--;
                if(ind[v]==0)
                    q.push(v);
            }
        }
        
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};