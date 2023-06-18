class Solution {
    int mod = 1000000007;
    vector<vector<int>> dp;
    int dfs(int r,int c,vector<vector<int>> &grid,int prev){
        int m = grid.size(), n = grid[0].size();

        if(-1!=dp[r][c]) return dp[r][c];

        int paths = 1;
        vector<int> directions[] = {{-1,0},{0,1},{1,0},{0,-1}};
        for(auto d : directions){
            int nr = d[0]+r;
            int nc = d[1]+c;
            if(nr<m and nc<n and nr>=0 and nc>=0 and grid[nr][nc]>prev){
                paths = (paths%mod + (dfs(nr,nc,grid,grid[nr][nc]))%mod)%mod;
            }
        }
        return dp[r][c] = paths;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        dp = vector<vector<int>>(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = (ans%mod + dfs(i,j,grid,grid[i][j])%mod)%mod;
            }
        }
        return ans;
    }
};