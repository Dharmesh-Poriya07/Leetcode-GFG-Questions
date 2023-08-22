class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(0<n){
            ans.push_back('A'+(n-1)%26);
            
            n = (n-1)/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};