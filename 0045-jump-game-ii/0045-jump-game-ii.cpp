class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<long> dp(n,INT_MAX);
        dp[n-1] = 0;
        for(int i=n-2;0<=i;i--){
            if(0<nums[i]){
                if(nums[i]>=n-i-1)
                    dp[i] = 1;
                else{
                    for(int j=1;j<=nums[i];j++){
                        dp[i] = min(dp[i],1+min(dp[i+1]!=-1?dp[i+1]:INT_MAX-1,dp[i+j]!=-1?dp[i+j]:INT_MAX-1));
                    }
                }
            }else{
                dp[i] = -1;
            }
        }
        return dp[0];
    }
};