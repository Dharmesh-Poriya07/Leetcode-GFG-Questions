class Solution {
public:
    int bfsOfGraph(vector<int> adj[], int src,vector<bool> &vis)
    {
        queue<int> q;
        q.push(src);
        vis[src] = true;
        int tnic = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            tnic ++;
            for (auto &v : adj[u])
            {
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        return tnic;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];
        for(auto e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n,false);
        long long ans = 0;
        long long copy_n = n;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int tnic = bfsOfGraph(graph,i,vis); // tnic = total nodes in component
                copy_n -= tnic;
                ans += ((long long)tnic*copy_n);
            }
        }
        return ans;
    }
};
