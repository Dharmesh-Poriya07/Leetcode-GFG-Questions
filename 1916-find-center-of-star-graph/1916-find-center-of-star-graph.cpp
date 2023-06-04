class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int> degree(n,0);
        for(auto e : edges){
            degree[e[0]-1] ++;
            degree[e[1]-1] ++;
        }
        for(int i=0;i<n;i++){
            if(degree[i] == n-1)
                return i+1;
        }
        return -1;
    }
};