class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_map<char,int> m;
        m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = 1;
        m['A'] = m['E'] = m['I'] = m['O'] = m['U'] = 1;
        int countLeft = 0;
        int countRight = 0;
        int left = 0;
        int right = s.size()-1;
        while(left < right){
            if(0<m[s[left]]) countLeft ++;
            if(0<m[s[right]]) countRight ++;
            left ++;
            right --;
        }
        return countLeft==countRight;
    }
};