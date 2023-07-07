class Solution {
    int dp[501][501];
    int solve(string &w1,string &w2,int i,int j){

        if(j<0) return i+1;
        if(i<0) return j+1;

        if(-1!=dp[i][j]) return dp[i][j];

        if(w1[i]==w2[j]) return solve(w1,w2,i-1,j-1);
        int _insert = 1 + solve(w1,w2,i,j-1);
        int _delete = 1 + solve(w1,w2,i-1,j);
        int _replace = 1 + solve(w1,w2,i-1,j-1);

        return dp[i][j] = min(_replace, min(_insert,_delete));
    }
public:
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int n = word1.size(), m=word2.size();
        return solve(word1,word2,n-1,m-1);
    }
};