class Solution {
private:
    bool dfs(vector<vector<int>> &graph,vector<bool> &visited,int s,int d){
        if(s==d) return true;
        visited[s] = true;
        for(auto &adj : graph[s]){
            if(!visited[adj]){
                if(dfs(graph,visited,adj,d))
                    return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n+1);
        for(auto &e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n+1,false);
        return dfs(graph,visited,source,destination);
    }
};