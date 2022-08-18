class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> presum_freq;
        presum_freq[0]++;
        int count = 0,presum = 0;
        for(int num : nums){
            presum += num;
            if(0<presum_freq[presum-k])
                count += presum_freq[presum-k];
            presum_freq[presum]++;
        }
        return count;
    }
};