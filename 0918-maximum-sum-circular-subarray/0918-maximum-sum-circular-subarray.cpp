class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minsum,maxsum,totalsum=0,n;
        minsum = INT_MAX;
        maxsum = INT_MIN;
        n = nums.size();
        // kadanes algorithm
        for(int i=0, curr=0;i<n;i++){
            totalsum += nums[i];
            curr += nums[i];
            maxsum = max(maxsum,curr);
            if(0>curr)
                curr = 0;
        }
        
        for(int i=0, curr=0;i<n;i++){
            curr += nums[i];
            minsum = min(minsum,curr);
            if(0<curr)
                curr = 0;
        }
        int circularsum = totalsum-minsum;
        if(0==circularsum) return maxsum;
        return max(maxsum,circularsum);
    }
};