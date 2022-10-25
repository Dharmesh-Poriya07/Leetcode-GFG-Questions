class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1,s2;
        s1 = s2 = "";
        for(string s : word1)
            for(char ch : s)
                s1.push_back(ch);
        
        for(string s : word2)
            for(char ch : s)
                s2.push_back(ch);
        
        return s1==s2;
    }
};