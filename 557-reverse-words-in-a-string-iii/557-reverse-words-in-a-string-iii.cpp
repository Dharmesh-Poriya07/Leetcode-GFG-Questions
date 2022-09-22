class Solution {
    void reverseS(string &s,int l,int r){
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }
public:
    string reverseWords(string s) {
        int l=0;
        int r=0;
        while(s.size()>r){
            if(' '!=s[r]){
                r++;
                continue;
            }
            reverseS(s,l,r-1);
            r++;
            l = r;
        }
        reverseS(s,l,r-1);
        return s;
    }
};