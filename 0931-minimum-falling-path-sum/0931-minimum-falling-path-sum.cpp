class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        vector<vector<int>> dp(n,vector<int>(n));
        int minpath = INT_MAX;
        for(int j=0;j<n;j++){
            dp[n-1][j] = matrix[n-1][j];
            minpath = min(minpath,matrix[n-1][j]);
        }
        if(1<n) minpath = INT_MAX;
        for(int i=n-2;0<=i;i--){
            for(int j=0;j<n;j++){
                if(0==j){
                    if(j+1<n) dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]);
                    else dp[i][j] = dp[i+1][j];
                }else if(n-1==j){
                    if(j-1>=0) dp[i][j] = min(dp[i+1][j],dp[i+1][j-1]);
                    else dp[i][j] = dp[i+1][j];
                }else{
                    dp[i][j] = min(dp[i+1][j],min(dp[i+1][j+1],dp[i+1][j-1]));
                }
                dp[i][j] += matrix[i][j];
                if(0==i) minpath = min(minpath,dp[i][j]);
            }
        }
        return minpath;
    }
};