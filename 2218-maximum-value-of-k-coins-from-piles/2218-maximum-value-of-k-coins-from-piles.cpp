class Solution {
public:
    int helper(vector<vector<int>>& piles, vector<vector<int>> &dp,int k,int ind){
        if(piles.size()<=ind) return 0;
        
        if(-1!=dp[ind][k]) return dp[ind][k];
        
        int mx = 0;
        mx = max(mx,helper(piles,dp,k,ind+1));
        
        for(int i=0;i<piles[ind].size();i++){
            if(i+1<=k){
                mx = max(mx,piles[ind][i]+helper(piles,dp,k-i-1,ind+1));
            }else
                break;
            
        }
        return dp[ind][k] = mx;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        
        for(int i=0;i<n;i++)
            for(int j=1;j<piles[i].size();j++)
                piles[i][j] += piles[i][j-1];
        
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        
        return helper(piles,dp,k,0);
    }
};