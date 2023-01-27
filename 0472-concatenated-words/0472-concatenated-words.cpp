class Solution {
private:
    unordered_map<string,int> mp;
    bool dfs(string w,int idx){
        if(idx==w.size()) return true;
        string temp = "";
        for(int i=idx;i<w.size();i++){
            temp.push_back(w[i]);
            if(0<mp[temp] and dfs(w,i+1)) 
                return true;
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        mp.clear();
        for(string &w : words) mp[w]++;
        vector<string> ans;
        for(string &w : words){
            mp[w]--;
            if(dfs(w,0)){
                ans.push_back(w);
            }
            mp[w]++;
        }
        return ans;
    }
};