class Solution {
private:
    vector<vector<int>> all_paths;
    vector<int> current_path;
    void dfs(vector<vector<int>> &graph,int src){
        if(src == graph.size()-1){
            current_path.push_back(src);
            all_paths.push_back(current_path);
            current_path.pop_back();
            return ;
        }
        current_path.push_back(src);
        for(auto adj : graph[src])
            dfs(graph,adj);
        current_path.pop_back();
        return;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int n = g.size();
        all_paths = vector<vector<int>>();
        current_path = vector<int>();
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++)
            for(auto childs : g[i])
                graph[i].push_back(childs);
        
        dfs(graph,0);
        return all_paths;
    }
};