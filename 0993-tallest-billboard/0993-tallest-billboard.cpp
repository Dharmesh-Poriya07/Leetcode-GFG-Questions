class Solution {
public:
    int dp[21][10001];
    int solve(int sum,int index,vector<int> &rods){
        if(index == rods.size()){
            if(0==sum) return 0;
            return INT_MIN;
        }

        if(-1 != dp[index][sum+5000]) return dp[index][sum+5000];

        int op1 = rods[index] + solve(sum+rods[index],index+1,rods);
        int op2 = solve(sum-rods[index],index+1,rods);
        int op3 = solve(sum,index+1,rods);

        return dp[index][sum+5000] = max(op3,max(op1,op2));
    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,rods);
    }
};