class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int lis = 1;
        vector<int> dp(nums.size());
        dp[0] = 1;
        for(int i=1;i<nums.size();i++){
            int maxlis = 0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[j]>maxlis){
                    maxlis = dp[j];
                }
            }
            lis = max(lis,maxlis+1);
            dp[i] = maxlis+1;
        }
        return lis;
    }
};