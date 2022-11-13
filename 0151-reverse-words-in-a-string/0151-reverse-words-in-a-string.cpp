class Solution {
public:
    string reverseWords(string s) {
        vector<string> temp;
        for(int i=0;i<s.size();i++){
            if(' '==s[i]) continue;
            string te = "";
            while(i<s.size() and ' '!=s[i]){
                te.push_back(s[i]);
                i++;
            }
            temp.push_back(te);
        }
        string ans = "";
        for(int i=temp.size()-1;0<=i;i--){
            for(char ch : temp[i])
                ans.push_back(ch);
            if(0!=i)
                ans.push_back(' ');
        }
        return ans;
    }
};