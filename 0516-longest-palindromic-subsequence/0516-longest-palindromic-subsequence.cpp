class Solution {
public:
    int longestPalindromeSubseq(string text1) {
        string text2 = text1;
        reverse(text2.begin(),text2.end());
        int t1 = text1.size();
        int t2 = text2.size();
        vector<vector<int>> dp(t1+1,vector<int>(t2+1,-1));
        for(int i=0;i<=t1;i++) dp[i][0] = 0;
        for(int j=0;j<=t2;j++) dp[0][j] = 0;
        for(int i=1;i<=t1;i++){
            for(int j=1;j<=t2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        // int ans = lcs(text1,text2,t1,t2,dp);
        // return ans;
        return dp[t1][t2];
    }
};