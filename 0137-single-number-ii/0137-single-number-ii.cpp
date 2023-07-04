class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int e=0, bit_count=0;
        long ans = 0;
        for(int i=0;i<32;i++){
            bit_count = 0;
            for(int j=0;j<nums.size();j++){
                bit_count += (nums[j]&1?1:0);
                nums[j] >>= 1;
            }
            if(bit_count%3){
                ans += pow(2,e);
            }
            e++;
        }
        return ans;
    }
};