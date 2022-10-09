class Solution {
    bool h1(string &s,int low,int high){
        int delcount = 0;
        while(low<high){
            if(s[low]!=s[high]){
                if(s[low+1]==s[high])
                    low ++;
                else if(s[high-1]==s[low])
                    high --;
                else 
                    return false;
                delcount++;
                if(1<delcount) return false;
            }else{
                low ++;
                high --;
            }
            
        }
        return true;
    }
    bool h2(string &s,int low,int high){
        int delcount = 0;
        while(low<high){
            if(s[low]!=s[high]){
                if(s[high-1]==s[low])
                    high --;
                else if(s[low+1]==s[high])
                    low ++;
                else 
                    return false;
                delcount++;
                if(1<delcount) return false;
            }else{
                low ++;
                high --;
            }
            
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int delcount = 0;
        int low = 0,high=s.size()-1;
        bool first = h1(s,low,high);
        bool second = h2(s,low,high);
        return first||second;
    }
};