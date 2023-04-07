class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(0==vis[i]){
                queue<vector<int>> q;
                q.push({i,1});
                vis[i] = 1;
                while(!q.empty()){
                    auto curr = q.front(); q.pop();
                    for(int adj : graph[curr[0]]){
                        if(0==vis[adj]){
                            q.push({adj,1==curr[1]?2:1});
                            vis[adj] = 1==curr[1]?2:1;
                        }else{
                            if(vis[adj]==curr[1])
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};