class Solution {
public:
    vector<long long> dp;
    long long solve(vector<vector<int>>& q,int ind){
        if(ind >= q.size()) return 0;
        
        if(-1 != dp[ind]) return dp[ind];
        
        long long choosen = q[ind][0] + solve(q,ind+q[ind][1]+1);
        long long notchoosen = solve(q,ind+1);
        return dp[ind] = max(choosen,notchoosen);
    }
    long long mostPoints(vector<vector<int>>& q) {
        dp = vector<long long>(q.size(),-1);
        return solve(q,0);
    }
};