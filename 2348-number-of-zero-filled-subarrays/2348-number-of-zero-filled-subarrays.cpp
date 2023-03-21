class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int low,high;
        low = high = 0;
        while(nums.size()>high){
            if(0==nums[low]){
                while(nums.size()>high && 0==nums[high]){
                    high ++;
                }
                long long len = high-low;
                ans += ((len*(len+1))/2);
                low = high;
            }else{
                low ++;
                high ++;
            }
        }
        return ans;
    }
};