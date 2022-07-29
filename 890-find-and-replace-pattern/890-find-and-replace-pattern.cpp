class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(string w : words){
            unordered_map<char,char> mp1,mp2;
            int i=0;
            for(;pattern.size()>i;i++){
                if((0==mp1[pattern[i]] && 0==mp2[w[i]]) || (w[i]==mp1[pattern[i]] && pattern[i]==mp2[w[i]])){
                    mp1[pattern[i]] = w[i];
                    mp2[w[i]] = pattern[i];
                }else{
                    break;
                }
            }
            if(i==w.size()){
                ans.push_back(w);
            }
        }
        return ans;
    }
};