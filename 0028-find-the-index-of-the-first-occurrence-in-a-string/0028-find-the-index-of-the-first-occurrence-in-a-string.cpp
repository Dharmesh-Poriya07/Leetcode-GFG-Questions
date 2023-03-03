class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(m>n) return -1;
        int i,j=0;
        i = j = 0;
        int index = -1;
        while(i<n){
            if(haystack[i]==needle[j]) j++;
            else{
                if(0!=j) i -= j;
                j=0;
            } 
            i++;
            if(j==m){
                index = i-m;
                break;
            }
        }
        return index;
    }
};