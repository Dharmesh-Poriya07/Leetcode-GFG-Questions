class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int rank = 0;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        vector<int> edges(n,0);
        for(auto r : roads){
            edges[r[0]]++;
            edges[r[1]]++;
            vis[r[0]][r[1]] = vis[r[1]][r[0]] = true;
        } 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                rank = max(rank,edges[i]+edges[j]-vis[i][j]);
            }
        }
        return rank;
    }
};