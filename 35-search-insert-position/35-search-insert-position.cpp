class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target>nums.back()) return nums.size();
        // if(target<nums[0]) return 0;
        int low,high,ceil;
        ceil = low = 0,high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                low = mid+1;
            }else{
                ceil = mid;
                high = mid-1;
            }
        }
        return ceil;
    }
};