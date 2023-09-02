class Solution {
public:
    unordered_set<string> hash;
    vector<int> dp;
    int solve(string &s,int ind){
        if(ind==s.size()) return 0;
        if(-1!=dp[ind]) return dp[ind];
        string tmp = "";
        int ans = INT_MAX;
        ans = 1+solve(s,ind+1);
        for(int i=ind;i<s.size();i++){
            tmp.push_back(s[i]);
            if(hash.end()!=hash.find(tmp)){
                ans = min(ans,solve(s,i+1));
            }
        }
        return dp[ind] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        dp = vector(s.size(),-1);
        for(auto s : dictionary) hash.insert(s);
        return solve(s,0);
    }
};