class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            int mn = INT_MAX;
            for(int j=1;j*j<=i;j++){
                mn = min(mn,dp[i-j*j]);
            }
            dp[i] = mn+1;
        }
        return dp[n];
    }
};