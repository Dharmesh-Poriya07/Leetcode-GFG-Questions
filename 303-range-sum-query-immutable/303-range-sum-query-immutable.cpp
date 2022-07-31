class NumArray {
private:
    vector<int> presum;
public:
    NumArray(vector<int>& nums) {
        presum = vector<int>(nums.size());
        presum[0] = nums[0];
        for(int i=1;nums.size()>i;i++){
            presum[i] = presum[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return (0==left?presum[right]:presum[right]-presum[left-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */