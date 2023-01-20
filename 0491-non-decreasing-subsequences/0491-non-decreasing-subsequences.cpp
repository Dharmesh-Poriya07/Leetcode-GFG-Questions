class Solution {
private:
    set<vector<int>> ans;
    void recursive(vector<int> &nums,int ind,vector<int> &temp){
        if(ind == nums.size()){
            if(1<temp.size()){
                ans.insert(temp);
            }
            return;
        }
        
        int current = nums[ind];
        int prev = (0==temp.size()?INT_MIN:temp.back());
        if(current>=prev){
            // element taken
            temp.push_back(current);
            recursive(nums,ind+1,temp);
            temp.pop_back();
            // element not taken
            recursive(nums,ind+1,temp);
        }else{
            recursive(nums,ind+1,temp);
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        recursive(nums,0,temp);
        vector<vector<int>> result;
        for(auto it : ans)
            result.push_back(it);
        return result;
    }
};