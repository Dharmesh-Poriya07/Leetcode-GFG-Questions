class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> remainder;
        remainder[0]=-1;
        int sum = nums[0];
        if(0!=sum%k)
            remainder[sum%k] = 0;
        for(int i=1;i<nums.size();i++){
            sum += nums[i];
            int rem = sum%k;
            if(remainder.end()!=remainder.find(rem)){
                if(1<i-remainder[rem]){
                    return true; 
                }
            } 
            else
                remainder[rem] = i;
        }
        return false;
    }
};