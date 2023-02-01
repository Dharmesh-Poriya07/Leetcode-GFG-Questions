class Solution {
    bool isValid(string &str,string &pattern){
        if(0!=str.size()%pattern.size()) return false;
        int i=0,j=0;
        int n = str.size();
        int m = pattern.size();
        while(i<n and str[i]==pattern[j]){
            i++;
            j++;
            j %= m;
        }
        return i==n;
    }
    string solve(string &s1,string &s2){
        string ans = "";
        string prefix = "";
        for(int i=0;i<s1.size();i++){
            prefix.push_back(s1[i]);
            if(isValid(s1,prefix) and isValid(s2,prefix))
                ans = prefix;
        }
        return ans;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        string gcd;
        if(str2.size()<=str1.size()){
            gcd = solve(str2,str1);
        }else{
            gcd = solve(str1,str2);
        }
        return gcd;
    }
};