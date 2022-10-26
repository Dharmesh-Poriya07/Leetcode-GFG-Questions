class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> remainder;
        remainder[0]=-1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int rem = sum%k;
            if(remainder.end()==remainder.find(rem))
                remainder[rem] = i;
            else if(1<i-remainder[rem])
                return true;
                
        }
        return false;
    }
};