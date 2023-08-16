class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>& grid,int r,int c){
        int n = grid.size(), m=grid[0].size();
        if(r==n-1 and c==m-1) return grid[r][c];
        if(r>=n or c>=m) return INT_MAX;

        if(-1 != dp[r][c]) return dp[r][c];

        int right = solve(grid,r,c+1);
        int bottom = solve(grid,r+1,c);

        return dp[r][c] = grid[r][c]+min(right,bottom);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0);
    }
};