class Solution {
    int mod = 1e9+7;
    vector<int> dp;
    int solve(int curr,int low,int high,int zero,int one){
        if(curr >= high) return 0;
        
        if(-1 != dp[curr]) return dp[curr];
        
        int c0 = 0,c1 = 0;
        int temp = curr + zero;
        if(temp>=low and temp<=high){
            c0 = 1 + solve(temp,low,high,zero,one);
        }else{
            c0 = solve(curr+zero,low,high,zero,one);
        }
        temp = curr + one;
        if(temp>=low and temp<=high){
            c1 = 1 + solve(temp,low,high,zero,one);
        }else{
            c1 = solve(curr+one,low,high,zero,one);
        }
        return dp[curr] = (c0+c1)%mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        dp = vector<int>(high,-1);
        return solve(0,low,high,zero,one);
    }
};