class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(n-1==i && m-1==j){
                    dp[i][j] = grid[i][j];
                }else if(n-1==i){
                    dp[i][j] = grid[i][j]+dp[i][j+1];
                }else if(m-1==j){
                    dp[i][j] = grid[i][j]+dp[i+1][j];
                }else{
                    dp[i][j] = grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};