class Solution {
    int mod = 1e9+7;
    vector<int> dp;
    int solve(int curr,int &low,int &high,int &zero,int &one){
        if(curr > high) return 0;
        
        if(-1 != dp[curr]) return dp[curr];
        
        int c0 = 0,c1 = 0;
        int temp0 = (curr + zero)>=low and (curr + zero)<=high;
        int temp1 = (curr + one)>=low and (curr + one)<=high;
        
        c0 = temp0 + solve(curr + zero,low,high,zero,one);
        c1 = temp1 + solve(curr + one,low,high,zero,one);
        
        return dp[curr] = (c0+c1)%mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        dp = vector<int>(high+1,-1);
        return solve(0,low,high,zero,one);
    }
};