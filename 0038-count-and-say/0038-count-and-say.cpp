class Solution {
public:
    string countAndSay(int n) {
        if(1==n) return "1";
        string s = countAndSay(n-1);
        string ans = "";
        int i=0;
        while(i<s.size()){
            int count = 1;
            int j=i+1;
            while(s.size()>j and s[j]==s[i]){
                count ++;
                j++;
            }
            ans += to_string(count);
            ans.push_back(s[i]);
            i = j;
        }
        return ans;
    }
};