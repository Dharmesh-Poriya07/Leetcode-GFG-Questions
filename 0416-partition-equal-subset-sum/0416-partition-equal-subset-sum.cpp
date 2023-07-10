class Solution {
public:
    int dp[201][10001];
    bool solve(vector<int>& nums,int ind,int sum){
        if(0==sum) return true;
        if(sum<0) return false;
        if(ind==nums.size()) return false;

        if(-1 != dp[ind][sum]) return dp[ind][sum];

        bool t = solve(nums,ind+1,sum-nums[ind]);
        bool nt = solve(nums,ind+1,sum);

        return dp[ind][sum] = t or nt;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums),end(nums),0);
        if(1&sum) return false;
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,sum>>1);
    }
};