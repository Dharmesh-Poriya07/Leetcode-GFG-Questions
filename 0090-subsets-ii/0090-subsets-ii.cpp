class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums,int ind,vector<int> &curr){
        if(ind>=nums.size()+1) return;
        ans.push_back(curr);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind and nums[i]==nums[i-1]) continue;

            curr.push_back(nums[i]);
            solve(nums,i+1,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        ans.clear();
        solve(nums,0,curr);
        return ans;
    }
};