class Solution {
    bool isPalindrome(string &s,int low,int high){
        while(low<high){
            if(s[low] != s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int low = 0,high=s.size()-1;
        
        while(low<high){
            if(s[low]!=s[high]){
                bool flag = false;
                flag = isPalindrome(s,low,high-1);
                if(!flag)
                    return isPalindrome(s,low+1,high);
                return flag;
            }else{
                low ++;
                high --;
            }
            
        }
        return true;
    }
};