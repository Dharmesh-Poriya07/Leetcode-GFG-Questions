class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2,vector<int>(n));
        dp[0][0] = nums[0];
        dp[1][0] = 0;
        for(int i=1;i<n;i++){
            dp[0][i] = dp[1][i-1]+nums[i];
            dp[1][i] = max(dp[1][i-1],dp[0][i-1]);
        }
        return max(dp[0][n-1],dp[1][n-1]);
    }
};