class Solution {
private:
    vector<vector<string>> ans;
    bool isPalindrome(string &s){
        int left = 0;
        int right = s.size()-1;
        while(left<right)
            if(s[left++]!=s[right--]) return false;
        
        return true;
    }
    void helper(string &s,int ind,vector<string> temp){
        if(ind == s.size()){
            ans.push_back(temp);
            return;
        }
        string t = "";
        for(int i=ind;i<s.size();i++){
            t.push_back(s[i]);
            if(isPalindrome(t)){
                temp.push_back(t);
                helper(s,i+1,temp);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        helper(s,0,temp);
        return ans;
    }
};