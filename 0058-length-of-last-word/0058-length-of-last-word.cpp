class Solution {
public:
    int lengthOfLastWord(string s) {
        while(0<s.size() and ' '==s.back()) s.pop_back();
        int mxlength = 0;
        while(0<s.size() and ' '!=s.back()){
            mxlength++;
            s.pop_back();
        }
        return mxlength;
    }
};