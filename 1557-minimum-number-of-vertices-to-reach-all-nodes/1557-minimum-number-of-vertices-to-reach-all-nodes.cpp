class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> ans, indegree(n,0);
        
        for(auto e : edges) indegree[e[1]] ++;
        
        for(int i=0;i<n;i++) if(0==indegree[i]) ans.push_back(i);
        
        return ans;
    }
};