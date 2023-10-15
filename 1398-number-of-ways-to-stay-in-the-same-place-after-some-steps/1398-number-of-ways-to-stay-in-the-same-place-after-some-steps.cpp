class Solution {
public:
    int len,mod;
    int dp[501][501];
    int solve(int steps,int ind){
        if(steps==0) return (0==ind)?1:0;
        if(ind<0 or ind>=len) return 0;

        if(-1!=dp[steps][ind]) return dp[steps][ind];

        int ans = 0;
        ans = (ans%mod + solve(steps-1,ind-1)%mod)%mod;
        ans = (ans%mod + solve(steps-1,ind)%mod)%mod;
        ans = (ans%mod + solve(steps-1,ind+1)%mod)%mod;
        return dp[steps][ind] = ans;
    }
    int numWays(int steps, int arrLen) {
        mod = 1000000007;
        len = arrLen;
        memset(dp,-1,sizeof(dp));

        return solve(steps,0);
    }
};