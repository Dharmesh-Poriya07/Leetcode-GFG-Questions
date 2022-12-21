class Solution {
    bool dfs(vector<vector<int>> &graph,vector<char> &colors,int src,char cc){
        colors[src] = cc;
        for(auto adj : graph[src]){
            if(cc==colors[adj] or ('0'==colors[adj] and !dfs(graph,colors,adj,('B'==cc?'R':'B')))) return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<char> colors(n+1,'0');
        vector<vector<int>> graph(n+1);
        for(auto d : dislikes){
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }
        for(int i=1;i<n+1;i++){
            if('0'==colors[i])
                if(!dfs(graph,colors,i,'B'))
                    return false;
        }
        return true;
    }
};