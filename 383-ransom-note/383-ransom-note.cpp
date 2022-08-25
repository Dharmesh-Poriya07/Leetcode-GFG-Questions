class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> freq;
        for(char ch : magazine)
            freq[ch]++;
        for(char ch : ransomNote){
            if(0<freq[ch])
                freq[ch]--;
            else 
                return false;
        }
        return true;
    }
};