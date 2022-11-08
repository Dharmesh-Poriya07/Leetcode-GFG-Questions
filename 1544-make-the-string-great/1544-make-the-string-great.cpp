class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        ans.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            if(0==ans.size()){
                ans.push_back(s[i]);
                continue;
            }
            char bc = ans.back();
            char cc = s[i];
            if((bc+32==cc) or (bc-32==cc)) ans.pop_back();
            else ans.push_back(s[i]);
        }
        return ans;
    }
};