class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int last_invalid_index, last_min_k, last_max_k;
        last_invalid_index = last_min_k = last_max_k = -1;
        
        long long count = 0;
        for(int i=0;i<n;i++){
            if(nums[i] >= minK and nums[i] <= maxK){
                if(nums[i]==minK) last_min_k = i;
                if(nums[i]==maxK) last_max_k = i;
                
                count += max(0,min(last_min_k,last_max_k)-last_invalid_index);
            }else{
                last_invalid_index = i;
                last_min_k = last_max_k = -1;
            }
        }
        return count;
    }
};