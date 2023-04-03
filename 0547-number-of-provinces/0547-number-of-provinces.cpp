class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i!=j and 1==isConnected[i][j]) adj[i].push_back(j);
        
        int total_province = 0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                total_province++;
                bfs(adj,visited,i);
            }
        }
        return total_province;
    }
    
    void bfs(vector<int> adj[],vector<bool> &vis, int src)
    {
        queue<int> q;
        q.push(src);
        vis[src] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto &v : adj[u])
            {
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        return;
    }
};