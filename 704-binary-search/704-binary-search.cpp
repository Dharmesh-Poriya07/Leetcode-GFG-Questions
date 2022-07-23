class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = -1;
        sort(nums.begin(),nums.end());
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                index = mid;
                break;
            }else if(nums[mid]<target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return index;
    }
};