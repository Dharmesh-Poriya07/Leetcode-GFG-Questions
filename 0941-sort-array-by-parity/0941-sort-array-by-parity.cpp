class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        while(left<right){
            if((nums[left]&1)==1 and (nums[right]&1)==0){
                swap(nums[left],nums[right]);
            }
            if((nums[left]&1)==0){
                left ++;
            }
            if((nums[right]&1)==1){
                right --;
            }
        }
        return nums;
    }
};