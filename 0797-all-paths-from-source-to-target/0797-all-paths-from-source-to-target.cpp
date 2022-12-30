class Solution {
private:
    vector<vector<int>> all_paths;
    vector<int> current_path;
    void dfs(vector<vector<int>> &graph,int src){
        for(auto adj : graph[src]){
            current_path.push_back(adj);
            if(adj == graph.size()-1){
                all_paths.push_back(current_path);
            }else dfs(graph,adj);
            current_path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int n = g.size();
        all_paths = vector<vector<int>>();
        current_path = vector<int>();
        current_path.push_back(0);
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++)
            for(auto childs : g[i])
                graph[i].push_back(childs);
        
        dfs(graph,0);
        return all_paths;
    }
};