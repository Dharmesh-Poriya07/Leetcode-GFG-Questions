class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,int> ump;
        for(auto s : strs){
            string temp = "";
            for(char ch : s){
                temp.push_back(ch);
                ump[temp]++;
            }
        }
        string ans = "";
        for(auto it : ump){
            if(it.second == n){
                if(ans.size()<it.first.size()){
                    ans = it.first;
                }
            }
        }
        return ans;
    }
};