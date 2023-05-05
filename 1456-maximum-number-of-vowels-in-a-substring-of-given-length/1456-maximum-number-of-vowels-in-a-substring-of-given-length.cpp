class Solution {
public:
    int maxVowels(string s, int k) {
        int crr_vowels = 0,mx_vowels = 0;
        for(int i=0;i<k-1;i++){
            if('a'==s[i] or 'e'==s[i] or 'o'==s[i] or 'i'==s[i] or 'u'==s[i])
                crr_vowels ++;
        }
        
        for(int i=k-1;i<s.size();i++){
            if('a'==s[i] or 'e'==s[i] or 'o'==s[i] or 'i'==s[i] or 'u'==s[i])
                crr_vowels ++;
            
            mx_vowels = max(mx_vowels,crr_vowels);
            
            if('a'==s[i-k+1] or 'e'==s[i-k+1] or 'o'==s[i-k+1] or 'i'==s[i-k+1] or 'u'==s[i-k+1])
                crr_vowels--;
        }
        
        return mx_vowels;
    }
};