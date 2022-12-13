class Solution {
    int sumSubarrayWithMid(vector<int> &nums,int mid){
        int count=1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>mid){
                count ++;
                sum = nums[i];
            }else sum += nums[i];
        }
        return count;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *(max_element(nums.begin(),nums.end()));
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = low;
        while(low<=high){
            int mid = low + (high-low)/2;
            int n = sumSubarrayWithMid(nums,mid);
            if(n>k) low = mid+1;
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};