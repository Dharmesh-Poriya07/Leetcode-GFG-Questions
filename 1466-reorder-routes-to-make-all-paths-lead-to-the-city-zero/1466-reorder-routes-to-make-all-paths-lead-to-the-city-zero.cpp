class Solution {
private:
    void dfs(vector<vector<int>> &graph,set<pair<int,int>> &s,vector<bool> &vis,int src,int &creq){
        vis[src] = true;
        for(int adj : graph[src]){
            if(!vis[adj]){
                if(s.end()!=s.find({src,adj}))
                    creq++;
                dfs(graph,s,vis,adj,creq);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        set<pair<int,int>> s;
        vector<bool> vis(n,false);
        for(auto con : connections){
            graph[con[0]].push_back(con[1]);
            graph[con[1]].push_back(con[0]);
            s.insert({con[0],con[1]});
        }
        int changeReq = 0;
        dfs(graph,s,vis,0,changeReq);
        return changeReq;
    }
};