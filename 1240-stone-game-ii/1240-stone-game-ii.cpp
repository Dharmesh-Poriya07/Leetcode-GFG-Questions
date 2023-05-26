class Solution {
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& piles,int turn,int ind,int m){
        int n = piles.size();
        if(ind>=n) return 0;

        if(-1!=dp[turn][ind][m]) return dp[turn][ind][m];

        int res = 1==turn?1000000:-1;   
        int score = 0;

        for(int x=1;x<=min(2*m,n-ind);x++){
            score += piles[ind+x-1];
            if(0==turn){
                // alice turn
                res = max(res,score+solve(piles,1,ind+x,max(m,x)));
            }else{
                // Bob turn
                res = min(res,solve(piles,0,ind+x,max(m,x)));
            }
        }
        return dp[turn][ind][m] = res;
    }
public:
    int stoneGameII(vector<int>& piles) {
        dp = vector<vector<vector<int>>>(2,vector<vector<int>>(piles.size()+1,vector<int>(piles.size()+1,-1)));
        return solve(piles,0,0,1);
    }
};