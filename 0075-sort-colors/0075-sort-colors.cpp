class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low,mid,high;
        low = mid = 0;
        high = nums.size()-1;
        
        while(mid <= high){
            if(0==nums[mid]){
                swap(nums[low],nums[mid]);
                mid ++;
                low ++;
            }else if(1 == nums[mid]){
                mid ++;
            }else{
                swap(nums[mid],nums[high]);
                high --;
            }
        }
    }
};