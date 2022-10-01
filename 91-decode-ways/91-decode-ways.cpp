class Solution {
public:
    int numDecodings(string s) {
        if('0'==s[0]) return 0;
		vector<int> dp(s.size(),0);
        dp[0] = 1;
        for(int i=1;i<s.size();i+=1){
            char current = s[i];
            char prev = s[i-1];
            int num = (prev-'0')*10+(current-'0');
            if('0'==current && '0'==prev){
                dp[i] = 0;
            }else if('0'==current && '0'!=prev){
                if(26>=num)
                    dp[i] = 1==i?1:dp[i-2];
                else
                    dp[i] = 0;
            }else if('0'!=current && '0'==prev){
                dp[i] = dp[i-1];
            }else{
                dp[i] = dp[i-1];
                if(26>=num)
                    dp[i] += 1==i?1:dp[i-2];
            }
        }
        return dp[s.size()-1];
    }
};