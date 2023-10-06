class Solution {
public:
    int dp[60];
    int solve(int n){
        if(1==n) return 1;
        
        int res = 0;
        for(int i=1;i<n;i++){
            int temp = max(i*(n-i),i*solve(n-i));
            res = max(res,temp);
        }
        return res;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i] = max(dp[i],max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};