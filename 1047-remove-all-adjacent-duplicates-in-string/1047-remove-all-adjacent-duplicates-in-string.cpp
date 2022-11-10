class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for(int i=0;i<s.size();i++){
            while(!ans.empty() and ans.back()==s[i]){
                ans.pop_back();
                i++;
            }
            if(s.size()>i)
                ans.push_back(s[i]);
        }
        return ans;
    }
};