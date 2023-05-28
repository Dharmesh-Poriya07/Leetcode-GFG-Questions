class Solution {
public:
int dp[102][102];
    int solve(int left,int right,vector<int> &cuts){
        if(right-left==1) return 0; // it's means there is only two cuts, but initially we have added two cuts 0 and n so we can not perform this cut.

        if(-1 != dp[left][right]) return dp[left][right];

        int cost = INT_MAX;
        for(int i=left+1;i<right;i++){
            cost = min(cost,cuts[right]-cuts[left] + solve(left,i,cuts) + solve(i,right,cuts));
        }

        return dp[left][right] = ((cost==INT_MAX)?0:cost);
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(begin(cuts),end(cuts));

        return solve(0,cuts.size()-1,cuts);
    }
};