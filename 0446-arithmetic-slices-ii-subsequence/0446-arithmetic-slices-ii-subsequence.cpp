class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<int,int>> dp(nums.size());
        int ans = 0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                long diff = (long)nums[i]-(long)nums[j];
                if(INT_MIN>=diff or INT_MAX<=diff) continue;
                if(0<dp[j][diff]){
                    ans += dp[j][diff];
                }
                dp[i][diff] += dp[j][diff]+1;
            }
        }
        return ans;
    }
};