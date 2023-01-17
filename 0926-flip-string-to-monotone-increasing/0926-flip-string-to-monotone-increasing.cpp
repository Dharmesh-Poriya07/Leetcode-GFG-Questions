class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> prefix(n),suffix(n);
        prefix[0] = suffix[n-1] = 0;
        for(int i=1;i<n;i++){
            prefix[i] = ('1'==s[i-1]?1:0)+prefix[i-1];
        }
        for(int i=n-2;0<=i;i--){
            suffix[i] = ('0'==s[i+1]?1:0)+suffix[i+1];
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,prefix[i]+suffix[i]);
        }
        return ans;
    }
};