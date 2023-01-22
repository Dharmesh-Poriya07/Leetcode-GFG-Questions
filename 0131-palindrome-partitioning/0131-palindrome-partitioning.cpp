class Solution {
private:
    vector<vector<string>> ans;
    int dp[17][17];
    bool isPalindrome(string &s,int left,int right){
        if(-1!=dp[left][right]) return dp[left][right];
        while(left<right){
            if(s[left]!=s[right]) return dp[left][right] = false;
            left++;
            right--;
        }
        return dp[left][right] = true;
    }
    void helper(string &s,int ind,vector<string> temp){
        if(ind == s.size()){
            ans.push_back(temp);
            return;
        }
        string t = "";
        for(int i=ind;i<s.size();i++){
            t.push_back(s[i]);
            if(isPalindrome(s,ind,i)){
                temp.push_back(t);
                helper(s,i+1,temp);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        memset(dp,-1,sizeof(dp));
        helper(s,0,temp);
        return ans;
    }
};