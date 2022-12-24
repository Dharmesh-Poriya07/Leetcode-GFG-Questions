class Solution {
public:
    int numTilings(int n) {
        if(3>n) return n;
        vector<long> dp(n+1);
        int mod = 1000000007;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i=4;i<n+1;i++){
            dp[i] = 2*dp[i-1]+dp[i-3];
            dp[i] %= mod;
        }
        return dp[n];
    }
};