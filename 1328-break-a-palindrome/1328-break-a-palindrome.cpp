class Solution {
public:
    string breakPalindrome(string str) {
        if(1==str.size()) return "";
        int n = str.size();
        for (int i = 0; i < n / 2; ++i) {
            if ('a' != str[i]) {
                str[i] = 'a';
                return str;
            }
        }
        str[n - 1] = 'b';
        return str;
    }
};