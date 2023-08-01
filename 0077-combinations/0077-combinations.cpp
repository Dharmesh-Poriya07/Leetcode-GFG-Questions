class Solution {
public:
    void solve(int start,int n,int k, vector<int> &cc, vector<vector<int>> &ans){
        if(0==k){
            ans.push_back(cc);
            return;
        }
        for(int i=start;i<=n;i++){
            cc.push_back(i);
            solve(i+1,n,k-1,cc,ans);
            cc.pop_back();
        }
        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cc; // current combinations
        solve(1,n,k,cc,ans);
        return ans;
    }
};