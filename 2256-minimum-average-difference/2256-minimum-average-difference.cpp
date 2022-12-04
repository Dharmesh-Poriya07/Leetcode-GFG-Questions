class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int ind = 0;
        long long currentMinDiff = INT_MAX;
        int n = nums.size();
        vector<long long> prefixSum(n);
        vector<long long> suffixSum(n);
        suffixSum[n-1] = nums.back();
        prefixSum[0] = nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i] = nums[i]+prefixSum[i-1];
        }
        for(int i=n-2;0<=i;i--){
            suffixSum[i] = nums[i]+suffixSum[i+1];
        }
        
        for(int i=0;i<n;i++){
            long long leftdiff = prefixSum[i];
            long long rightdiff = 0;
            if(n-1>i)
                rightdiff = suffixSum[i]-nums[i];
            leftdiff /= (long long)(i+1);
            if(n-1>i)
                rightdiff /= (long long)(n-i-1);
            long long avgdiff = abs(leftdiff-rightdiff);
            if(avgdiff<currentMinDiff){
                ind = i;
                currentMinDiff = avgdiff;
            }
        }
        return ind;
    }
};