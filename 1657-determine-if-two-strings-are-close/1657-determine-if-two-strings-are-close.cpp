class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;
        vector<int> freq1(26,0),freq2(26,0),unique1(26,0),unique2(26,0);
        for(int i=0;i<word1.size();i++){
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
            unique1[word1[i]-'a'] = 1;
            unique2[word2[i]-'a'] = 1;
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i] or unique1[i]!=unique2[i]) return false;
        }
        return true;
    }
};