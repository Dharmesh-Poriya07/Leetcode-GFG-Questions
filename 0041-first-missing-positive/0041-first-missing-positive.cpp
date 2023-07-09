class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=0 or nums[i]>n or nums[i]==i+1 or nums[nums[i]-1]==nums[i]) continue;
            swap(nums[i],nums[nums[i]-1]);
            i--;
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};