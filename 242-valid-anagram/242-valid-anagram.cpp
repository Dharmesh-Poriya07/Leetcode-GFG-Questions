class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26,0);
        for(char ch : s)
            freq[ch-'a'] ++;
        
        for(char ch : t)
            freq[ch-'a'] --;
        
        for(int f : freq)
            if(0!=f)
                return false;
        return true;
    }
};