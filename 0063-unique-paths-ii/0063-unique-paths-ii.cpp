class Solution {
public:
    long long dp[101][101];
    // int mod = 1e9+7;
    int solve(vector<vector<int>> &grid,int i,int j){
        int n = grid.size(), m = grid[0].size();
        if(i==-1 or j==-1 or grid[i][j]==1) return 0;
        if(i==0 and j==0) return 1;
        if(-1 != dp[i][j]) return dp[i][j];
        long long ans = 0;
        ans += solve(grid,i,j-1);
        ans += solve(grid,i-1,j);
        return dp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,n-1,m-1);
    }
};