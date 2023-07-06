class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int> &nums,int ind,int prev){
        if(ind==nums.size()) return 0;
        if(-1!=dp[ind][prev+1]) return dp[ind][prev+1];

        int taken=0,nottaken=0;
        if(prev==-1 or nums[ind]>nums[prev]){
            taken = 1+solve(nums,ind+1,ind);
        }
        nottaken = solve(nums,ind+1,prev);
        
        return dp[ind][prev+1] = max(taken,nottaken);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp = vector<vector<int>>(n,vector<int>(n+1,-1));
        return solve(nums,0,-1);
    }
};