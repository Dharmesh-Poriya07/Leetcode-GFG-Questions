class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int ans = 0;
        for(int i=2;nums.size()>i;i++){
            if(nums[i]+nums[i-1]>nums[i-2] and nums[i-1]+nums[i-2]>nums[i] and nums[i]+nums[i-2]>nums[i-1]){
                ans = nums[i]+nums[i-1]+nums[i-2];
                break;
            }
        }
        return ans;
    }
};