class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mxans = INT_MIN, n=nums.size();
        int prefix_sum = 1, suffix_sum = 1;
        for(int i=0,j=n-1;i<n and j>=0;i++,j--){
            if(prefix_sum==0) prefix_sum=1;
            if(suffix_sum==0) suffix_sum=1;

            prefix_sum *= nums[i];
            suffix_sum *= nums[j];

            mxans = max(mxans,prefix_sum);
            mxans = max(mxans,suffix_sum);
        }
        return mxans;
    }
};