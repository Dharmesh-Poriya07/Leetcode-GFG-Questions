class Solution {
private:
    vector<vector<int>> dp;
    int helper(vector<vector<int>> &pr,int ind,int prev){
        if(ind==pr.size()) return 0;
        if(-1==prev){
            return dp[ind+1][prev+1] = max(pr[ind][1]+helper(pr,ind+1,ind),helper(pr,ind+1,prev));
        }
        if(-1!=dp[ind+1][prev+1]) return dp[ind+1][prev+1];
        int op1=-1,op2 = -1;
        if(-1!=prev and ((pr[prev][0]==pr[ind][0]) or (pr[ind][1]<=pr[prev][1])))
            op1 = pr[ind][1] + helper(pr,ind+1,ind);
        op2 = helper(pr,ind+1,prev);
        return dp[ind+1][prev+1]  = max(op1,op2);
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>> pr;
        dp = vector<vector<int>>(scores.size()+1,vector<int>(scores.size()+1,-1));
        for(int i=0;i<scores.size();i++)
            pr.push_back({ages[i],scores[i]});
        sort(pr.rbegin(),pr.rend());
        return helper(pr,0,-1);
    }
};