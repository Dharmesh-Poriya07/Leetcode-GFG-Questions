class Solution {
private:
    
    int helper(vector<int>& nums, vector<int>& mul,int l,int ind,vector<vector<int>> &dp){
        int n = nums.size();
        if(ind==mul.size()){
            return 0;
        }
        if(INT_MIN!=dp[ind][l]) return dp[ind][l];
        
        int left = nums[l]*mul[ind] + helper(nums,mul,l+1,ind+1,dp);
        int right = nums[(n - 1) - (ind - l)]*mul[ind] + helper(nums,mul,l,ind+1,dp);
        
        return dp[ind][l] = max(left,right);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size();
        int m = multipliers.size();
        vector<vector<int>> dp(m,vector<int>(m+1,INT_MIN));
        return helper(nums,multipliers,0,0,dp);
    }
};