class Solution {
public:
    string reverseVowels(string s) {
        int left=0,right=s.size()-1;
        bool leftb=false,rightb=false;
        unordered_map<char,int> mp;
        mp['a'] = mp['e'] = mp['i'] = mp['o'] = mp['u'] = 1;
        mp['A'] = mp['E'] = mp['I'] = mp['O'] = mp['U'] = 1;
        while(left<right){
            if(!leftb and 0<mp[s[left]]){
                leftb = true;
            }
            if(!rightb and 0<mp[s[right]]){
                rightb = true;
            }
            if(leftb and rightb){
                leftb = rightb = false;
                swap(s[left],s[right]);
            }
            if(!leftb) left++;
            if(!rightb) right--;
        }
        
        return s;
    }
};