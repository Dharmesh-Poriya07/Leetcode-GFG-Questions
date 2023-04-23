class Solution {
public:
    vector<int> dp;
    int mod = 1e9+7;
    int solve(string &s,int &k,int ind){
        if(ind==s.size()) return 1;
        if(s[ind]=='0') return 0;
        
        if(-1 != dp[ind]) return dp[ind];
        
        int ans = 0;
        long long curr_num = 0;
        for(int i=ind;i<s.size();i++){
            curr_num *= 10;
            curr_num += (s[i]-'0');
            if(curr_num > k) break;
            ans = (ans + solve(s,k,i+1))%mod;
        }
        return dp[ind] = ans;
    }
    int numberOfArrays(string s, int k) {
        dp = vector<int>(s.size(),-1);
        return solve(s,k,0);
    }
};