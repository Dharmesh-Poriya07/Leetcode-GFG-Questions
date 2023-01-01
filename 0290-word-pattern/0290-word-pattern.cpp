class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        unordered_map<string,char> mstr;
        unordered_map<char,string> mchar;
        int j=0;
        while(j<s.size()){
            string word = "";
            while(j<s.size() and ' '!=s[j]){
                word.push_back(s[j]);
                j++;
            }
            j++;
            words.push_back(word);
        }
        if(words.size()!=pattern.size()) return false;
        int i=0;
        for(string word : words){
            auto itc = mchar.find(pattern[i]);
            auto its = mstr.find(word);
            if((mchar.end()==itc and mstr.end()!=its)or(mchar.end()!=itc and mstr.end()==its)) return false;
            if(mchar.end() == itc and mstr.end()==its){
                mchar[pattern[i]] = word;
                mstr[word] = pattern[i];
            }else if(mchar[pattern[i]]!=word or mstr[word]!=pattern[i]) return false;
            i++;
        }
        return true;
    }
};