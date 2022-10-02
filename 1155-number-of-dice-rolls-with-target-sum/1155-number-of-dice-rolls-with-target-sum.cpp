class Solution {
private:
    vector<vector<int>> dp;
    int m = 1e9+7;
    int modAdd(int a,int b){
        a %= m;
        b %= m;
        return (a+b)%m;
    }
    int helper(int n,int k,int sum,int target){
        if(sum>target)
            return 0;
        if(0==n){
            if(sum==target)
                return 1;
            return 0;
        }
        if(-1 != dp[n][sum])
            return dp[n][sum];
        int ans = 0;
        for(int i=1;i<=k;i++){
            ans = modAdd(ans,helper(n-1,k,sum+i,target));
        }
        return dp[n][sum] = ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        dp = vector<vector<int>>(n+1,vector<int>(target+1,-1));
        return helper(n,k,0,target);
    }
};