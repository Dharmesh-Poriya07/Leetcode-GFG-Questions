class Solution {
public:
    set<vector<int>> unique;
    void solve(vector<int>& nums,int ind,vector<int> curr){
        if(ind>=nums.size()){
            sort(curr.begin(),curr.end());
            unique.insert(curr);
            return;
        }

        curr.push_back(nums[ind]);
        solve(nums,ind+1,curr);
        curr.pop_back();
        solve(nums,ind+1,curr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.clear();
        solve(nums,0,{});

        for (auto it = unique.begin(); it != unique.end(); it++) {
            ans.push_back( * it);
        }
        return ans;
    }
};