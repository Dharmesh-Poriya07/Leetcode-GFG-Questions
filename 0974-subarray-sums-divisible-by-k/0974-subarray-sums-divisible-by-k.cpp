class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> presum_freq;
        presum_freq[0]++;
        int count = 0,presum = 0;
        for(int num : nums){
            presum += num;
            int rem = ((presum%k)+k)%k;
            if(0<presum_freq[rem])
                count += presum_freq[rem];
            presum_freq[rem]++;
        }
        return count;
    }
};