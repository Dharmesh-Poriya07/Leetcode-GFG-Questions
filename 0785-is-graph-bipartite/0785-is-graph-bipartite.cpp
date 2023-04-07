class Solution {
public:
    bool bfs(vector<vector<int>>& graph,vector<int> &vis,int src){
        queue<vector<int>> q;
        q.push({src,1});
        vis[src] = 1;
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            for(int adj : graph[curr[0]]){
                if(vis[adj]==curr[1]) return false;
                if(0==vis[adj]){
                    q.push({adj,1==curr[1]?2:1});
                    vis[adj] = 1==curr[1]?2:1;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
            if(0==vis[i])
                if(!bfs(graph,vis,i)) return false;
        
        return true;
    }
};