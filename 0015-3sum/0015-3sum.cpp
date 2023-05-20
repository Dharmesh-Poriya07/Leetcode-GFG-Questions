class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-2;i++){
            if(0==i or (0<i and nums[i]!=nums[i-1])){
                int low = i+1, high = nums.size()-1, target = 0-nums[i];
                
                while(low<high){
                    int sum = nums[low]+nums[high];
                    if(sum == target){
                        ans.push_back({nums[i],nums[low],nums[high]});
                        
                        while(low<high and nums[low]==nums[low+1]) low++;
                        while(low<high and nums[high]==nums[high-1]) high--;
                        low ++;
                        high --;
                    }else if(sum < target) low ++;
                    else high --;
                }
            }
        }
        return ans;
    }
};