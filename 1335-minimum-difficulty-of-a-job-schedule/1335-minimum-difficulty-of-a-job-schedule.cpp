class Solution {
private:
    vector<vector<int>> dp;
    int helper(vector<int>& jd,int ind,int d){
        if(1==d){
            int mx = 0;
            for(int i=ind;i<jd.size();i++)
                mx = max(mx,jd[i]);
            return mx;
        }
        if(-1!=dp[d][ind]) return dp[d][ind];
        
        int sum = INT_MAX;
        int cmx = 0;
        for(int i=ind;i<=jd.size()-d;i++){
            cmx = max(cmx,jd[i]);
            sum = min(sum,cmx+helper(jd,i+1,d-1));
        }
        return dp[d][ind] = sum;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d) return -1;
        dp = vector(d+1,vector<int>(jobDifficulty.size(),-1));
        return helper(jobDifficulty,0,d);
    }
};