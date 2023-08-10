class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low<=high){
            int mid = (low+high) >> 1;
            if(target == nums[mid]) return true;

            if(nums[low]==nums[mid] and nums[high]==nums[mid]){
                low ++;
                high --;
                continue;
            }

            if(nums[low] <= nums[mid]){
                if(target>=nums[low] and target<=nums[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{
                if(target>=nums[mid] and target<=nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};