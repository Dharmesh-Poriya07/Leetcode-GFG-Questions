class Solution {
public:
    bool dfs(int ind,string &s,unordered_set<string> &f,vector<int> &dp){
        int n = s.size();
        if(ind==n){
            return true;
        }
        if(-1 != dp[ind]) return dp[ind];
        string t = "";
        for(int i=ind;i<s.size();i++){
            t.push_back(s[i]);
            if(f.find(t)!=f.end()){
                if(dfs(i+1,s,f,dp))
                    return dp[ind] = true;
            }
        }
        
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& d) {
        unordered_set<string> f(d.begin(),d.end());
        vector<int> dp(s.size()+1,-1);
        return dfs(0,s,f,dp);
    }
};