class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        int c0,c1,c10,c11;
        c0=c1=c10=c11=0;
        for(int i=0;i<s.size();i++){
            if('0'==s[i]) c0++;
            else c1++;
            if('0'==t[i]) c10++;
            else c11++;
        }
        if((c0==s.size() and c10!=s.size()) or (c10==s.size() and c0!=s.size())) return false;
        return true;
    }
};