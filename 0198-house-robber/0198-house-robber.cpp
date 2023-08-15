class Solution {
public:
    int dp[101];
    int solve(vector<int> &nums,int ind){
        if(0>ind) return 0;
        if(-1 != dp[ind]) return dp[ind];
        int t = nums[ind] + solve(nums,ind-2);
        int nt = solve(nums,ind-1);

        return dp[ind] = max(t,nt);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,nums.size()-1);
    }
};