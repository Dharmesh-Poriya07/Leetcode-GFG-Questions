class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        for(int i=s.size()-1;0<=i;i--){
            if(' '==s[i]) continue;
            string word = "";
            while(0<=i and ' '!=s[i]){
                word.push_back(s[i]);
                i--;
            }
            for(int j=word.size()-1;0<=j;j--)
                ans.push_back(word[j]);
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};