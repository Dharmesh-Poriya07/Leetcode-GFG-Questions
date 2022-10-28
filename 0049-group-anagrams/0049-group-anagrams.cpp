class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>> mp;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto [s,ind] : mp){
            ans.push_back({});
            for(int i : ind)
                ans.back().push_back(strs[i]);
        }
        return ans;
    }
};