class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind,vector<int> &curr,vector<int> &cand,int target){
        if(0 == target){
            ans.push_back(curr);
            return;
        }
        if(ind>=cand.size() or 0 > target) return;

        if(target-cand[ind] >= 0){
            curr.push_back(cand[ind]);
            solve(ind,curr,cand,target-cand[ind]);
            curr.pop_back();
        }
        solve(ind+1,curr,cand,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        solve(0,curr,candidates,target);
        return ans;
    }
};