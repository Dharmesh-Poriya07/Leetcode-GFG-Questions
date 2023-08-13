class Solution {
private:
    vector<int> dp;
    bool helper(vector<int>& nums,int i){
        int n = nums.size();
        if(i==n) return true;
        if(-1!=dp[i]) return dp[i];
        bool res = false;
        if(i+1<n && nums[i]==nums[i+1]){
            res = res || helper(nums,i+2);
            if(i+2<n && nums[i]==nums[i+2]){
                res = res || helper(nums,i+3);
            }
        }
        
        if(i+2<n && nums[i]+1==nums[i+1] && nums[i+1]+1==nums[i+2]){
            res = res || helper(nums,i+3);
        }
        return dp[i] = res;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        if(2==n){
            return (nums[0]==nums[1]);
        }
        dp = vector(nums.size()+1,-1);
        return helper(nums,0);
    }
};