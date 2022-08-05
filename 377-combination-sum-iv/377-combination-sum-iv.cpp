class Solution {
private:
    vector<int> dp;
    int helper(vector<int> &nums,int target){
        if(0>target) return 0;
        if(0==target) return 1;
        if(-1!=dp[target]) return dp[target];
        int ans = 0;
        for(int i=0;i<nums.size() && nums[i]<=target;i++){
            ans += helper(nums,target-nums[i]);
        }
        return dp[target] = ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp = vector(target+1,-1);
        sort(nums.begin(),nums.end());
        return helper(nums,target);
    }
};