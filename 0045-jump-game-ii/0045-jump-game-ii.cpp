class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<long> dp(n,-1);
        dp[n-1] = 0;
        for(int i=n-2;0<=i;i--){
            if(0<nums[i]){
                dp[i] = INT_MAX;
                if(nums[i]>=n-i-1) dp[i] = 1;
                else
                    for(int j=1;j<=nums[i];j++)
                        if(-1!=dp[i+j])
                            dp[i] = min(dp[i],1+dp[i+j]);
            }else
                dp[i] = -1;
        }
        return dp[0];
    }
};