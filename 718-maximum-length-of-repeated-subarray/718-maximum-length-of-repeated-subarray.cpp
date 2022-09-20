class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int mx_subarr = 0;
        for(int i=1;n+1>i;i++){
            for(int j=1;m+1>j;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                mx_subarr = max(mx_subarr,dp[i][j]);
            }
        }
        return mx_subarr;
    }
};