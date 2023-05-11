class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& nums1, vector<int>& nums2,int ind1,int ind2){
        if(ind1==nums1.size() or ind2==nums2.size()) return 0;
        if(-1 != dp[ind1][ind2]) return dp[ind1][ind2];
        int choosen=0,notchoosen=0;
        int ti = -1;
        for(int i = ind2;i<nums2.size();i++){
            if(nums2[i]==nums1[ind1]){
                ti = i;
                break;
            }            
        }
        if(ti != -1){
            choosen = (1+solve(nums1,nums2,ind1+1,ti+1));
        }
        notchoosen = solve(nums1,nums2,ind1+1,ind2);
        return dp[ind1][ind2] = max(choosen,notchoosen);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return solve(nums1,nums2,0,0);
    }
};