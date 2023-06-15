class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int start=0, end=0;
        bool flag = false;

        for(int i=0,j=0;i<n;i++,j++) dp[i][j] = true;
        for(int i=0,j=1;j<n;i++,j++){
            if(s[i]==s[j]){
                dp[i][j] = true;
                if(!flag)
                    start=i, end=j, flag = true;
            }
        }

        for(int gap=2;gap<n;gap++){
            flag = false;

            for(int i=0,j=gap;j<n;i++,j++){
                if(s[i]==s[j] and dp[i+1][j-1]){
                    dp[i][j] = true;
                    if(!flag)
                        start=i, end=j, flag = true;
                }
            }
        }

        return s.substr(start,end-start+1);
    }
};