class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> presum_freq;
        presum_freq[0]++;
        int count = 0,presum = 0;
        for(int i=0;i<nums.size();i++){
            presum += nums[i];
            if(0<presum_freq[presum-k])
                count += presum_freq[presum-k];
            presum_freq[presum]++;
        }
        return count;
    }
};