class Solution {
private:
    int firstOccurance(vector<int>& nums, int target){
        int index = -1;
        int low,high;
        low = 0,high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                if(0!=mid && nums[mid-1]==target){
                    index = mid-1;
                    high = mid-2; 
                }else{
                    index = mid;
                    break;
                }
            }else if(nums[mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return index;
    }
    int lastOccurance(vector<int>& nums, int target){
        int index = -1;
        int low,high;
        low = 0,high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                if(nums.size()-1!=mid && nums[mid+1]==target){
                    index = mid+1;
                    low = mid+2; 
                }else{
                    index = mid;
                    break;
                }
            }else if(nums[mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return index;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firsto = firstOccurance(nums,target);
        int lasto = lastOccurance(nums,target);
        return {firsto,lasto};
    }
};