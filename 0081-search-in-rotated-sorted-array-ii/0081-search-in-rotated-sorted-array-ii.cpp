class Solution {
public:
    void reverseArr(vector<int> &nums,int left,int right){
        while(left<=right){
            swap(nums[left],nums[right]);
            left ++;
            right --;
        }
    }
    bool search(vector<int>& nums, int target) {
        int pivot = -1, n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                pivot = i-1;
                break;
            }
        }
        reverseArr(nums,0,pivot);
        reverseArr(nums,pivot+1,n-1);
        reverseArr(nums,0,n-1);
        return binary_search(nums.begin(),nums.end(),target);
    }
};