class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        for(int i=1;i<n+1;i++){
            if(1==i || 2==i) dp[i] = i;
            else dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};