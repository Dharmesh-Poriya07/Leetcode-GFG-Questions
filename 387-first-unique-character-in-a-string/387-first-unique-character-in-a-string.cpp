class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);
        for(char ch : s){
            freq[ch-'a']++;
        }
        int i=0;
        for(char ch : s){
            if(1==freq[ch-'a'])
                return i;
            i++;
        }
        return -1;
    }
};