class Solution {
    vector<vector<int>> dp;
    int solve(vector<int>& piles,int turn,int ind){
        int n = piles.size();
        if(ind>=n) return 0;

        if(-1!=dp[turn][ind]) return dp[turn][ind];

        int res = 1==turn?1e9:-1e9;   
        int score = 0;

        for(int x=1;x<=min(3,n-ind);x++){
            score += piles[ind+x-1];
            if(0==turn){
                // alice turn
                res = max(res,score+solve(piles,1,ind+x));
            }else{
                // Bob turn
                res = min(res,solve(piles,0,ind+x));
            }
        }
        return dp[turn][ind] = res;
    }
public:
    string stoneGameIII(vector<int>& piles) {
        dp = vector<vector<int>>(2,vector<int>(piles.size()+1,-1));
        int alice = solve(piles,0,0);
        int bob = accumulate(begin(piles),end(piles),0)-alice;
        if (alice > bob)
            return "Alice";
        else if (alice < bob)
            return "Bob";
        return "Tie";
    }
};