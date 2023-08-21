class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string tmp = s;
        tmp += s;
        tmp.pop_back();
        reverse(tmp.begin(),tmp.end());
        tmp.pop_back();
        reverse(tmp.begin(),tmp.end());

        return tmp.find(s) != string::npos;
    }
};