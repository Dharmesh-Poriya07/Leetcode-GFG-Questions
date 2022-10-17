class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> hash(26,0);
        for(char ch : sentence){
            hash[ch-'a'] ++;
        }
        for(int freq : hash)
            if(0==freq)
                return false;
        return true;
    }
};