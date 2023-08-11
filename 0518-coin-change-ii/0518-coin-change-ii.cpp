class Solution {
    int dp[301][5001];
    int solve(vector<int> &coins,int ind,int target){
        if(target<0) return 0;
        if(target==0) return 1;
        if(ind==coins.size()) return 0;

        if(-1!=dp[ind][target]) return dp[ind][target];
        
        int t = solve(coins,ind,target-coins[ind]);
        int nt = solve(coins,ind+1,target);

        return dp[ind][target] = t+nt;
    }
public:
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return solve(coins,0,amount);
    }
};