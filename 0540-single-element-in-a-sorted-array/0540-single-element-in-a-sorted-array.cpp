class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(1==nums.size()) return nums.back();
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if((0==mid and nums[mid+1]!=nums[mid]) or (nums.size()-1==mid and nums[mid-1]!=nums[mid]) or (nums[mid-1]!=nums[mid] and nums[mid+1]!=nums[mid])) return nums[mid];
            
            if(nums[mid-1]==nums[mid]){
                if(1==(mid+1)%2) high = mid-1;
                else low = mid+1;
            }else{
                if(1==(nums.size()-mid)%2) low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }
};