class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size();
        int cols = pizza[0].size();
        
        vector<vector<int>> presum(rows+1,vector<int>(cols+1,0));
        
        for(int i=rows-1;0<=i;i--){
            for(int j=cols-1;0<=j;j--){
                presum[i][j] = presum[i][j+1]+presum[i+1][j]-presum[i+1][j+1]+('A'==pizza[i][j]?1:0);
            }
        }
        vector<vector<vector<int>>> dp(k+1,vector<vector<int>>(rows+1,vector<int>(cols+1,-1)));
        // i,j and k will change so we need 3D DP.
        return solve(rows,cols,k-1,0,0,presum,dp);
    }
    
    int solve(int rows,int cols,int k,int row,int col,vector<vector<int>> &presum,vector<vector<vector<int>>> &dp){
        if(0==presum[row][col]) return 0;
        if(0==k) return 1;
        if(-1 != dp[k][row][col]) return dp[k][row][col];
        
        int ans = 0;
        
        // cutting horizontal
        for(int r=row+1;r<rows;r++){
            if(0<presum[row][col]-presum[r][col])
                ans = (ans+solve(rows,cols,k-1,r,col,presum,dp))%1000000007;
        }
        
        for(int c=col+1;c<cols;c++){
            if(0<presum[row][col]-presum[row][c])
                ans = (ans+solve(rows,cols,k-1,row,c,presum,dp))%1000000007;
        }
        
        return dp[k][row][col] = ans;
    }
};