class Solution {
public:
    int strangePrinter(string s) {
        if(s.size()==0)return 0;
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        for(int i=s.size()-1;i>=0;i--)
            for(int j=i;j<s.size();j++)
            {
                if(i==j)dp[i][j]=1;
                else
                {
                    int temp=dp[i][j-1]+1,m;
                    for(m=j-1;m>=i;m--)
                        if(s[m]==s[j])
                        {
                            if(m>0&&temp>dp[i][m-1]+dp[m][j-1])temp=dp[i][m-1]+dp[m][j-1];
                            else if(m==0)temp=dp[0][j-1];
                        }
                    dp[i][j]=temp;
                }
            }
        return dp[0][s.size()-1];
    }
};