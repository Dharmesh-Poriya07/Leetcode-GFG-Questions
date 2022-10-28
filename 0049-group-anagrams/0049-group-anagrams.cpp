class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<int>> mp;
        for(int i=0;i<strs.size();i++){
            map<char,int> f;
            for(char ch : strs[i])
                f[ch]++;
            mp[f].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto [f,ind] : mp){
            ans.push_back({});
            for(int i : ind)
                ans.back().push_back(strs[i]);
        }
        return ans;
    }
};