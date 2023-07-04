class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1,ans=0;
        int start=0,end=0;
        while(end<nums.size()){
            product *= nums[end];
            while(start<nums.size() and product >= k){
                product /= nums[start++];
            }
            if(product<k) ans += (end-start+1);
            end++;
        }
        return ans;
    }
};