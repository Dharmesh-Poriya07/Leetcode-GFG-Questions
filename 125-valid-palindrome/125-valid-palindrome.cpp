class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;s.size()>i;i++){
            if('A'<=s[i] and 'Z'>=s[i])
                s[i] += 32;
            else if(('a'<=s[i] and 'z'>=s[i]) or ('0'<=s[i] and '9'>=s[i]))
                continue;
            else
                s[i] = '.';
            
        }
        
        int low=0,high=s.size()-1;
        while(low<high){
            if('.'==s[low]){
                low ++;
                continue;
            }
            if('.'==s[high]){
                high--;
                continue;
            }
            if(s[low]!=s[high]){
                return false;
            }
            low ++;
            high--;
        }
        return true;
    }
};