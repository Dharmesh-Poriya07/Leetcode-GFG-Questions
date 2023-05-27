class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind,vector<int> &curr,const vector<int> &cand,int target){
        if(0 == target){
            ans.push_back(curr);
            return;
        }
        
        for(int i=ind;i<cand.size();i++){
            if(i>ind and cand[i]==cand[i-1]) continue;
            if(cand[i]>target) break;
            curr.push_back(cand[i]);
            solve(i+1,curr,cand,target-cand[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(begin(candidates),end(candidates));
        solve(0,curr,candidates,target);
        
        return ans;
    }
};