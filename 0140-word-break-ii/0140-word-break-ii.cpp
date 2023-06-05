class Solution {
public:
    vector<string> ans;
    void dfs(int ind,string temp,string &s,unordered_set<string> &f){
        int n = s.size();
        if(ind==n){
            ans.push_back(temp);
            return ;
        }

        string t = "";
        for(int i=ind;i<s.size();i++){
            t.push_back(s[i]);
            if(f.find(t)!=f.end()){
                dfs(i+1,temp+t+(i==n-1?"":" "),s,f);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& d) {
        string temp = "";
        unordered_set<string> f(d.begin(),d.end());
        dfs(0,temp,s,f);
        return ans;
    }
};