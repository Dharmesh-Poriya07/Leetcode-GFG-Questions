class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k,i;
        k=0;
        i=k+1;
        while(i<nums.size()){
            if(nums[k]!=nums[i])
                nums[++k] = nums[i];
            i++;
        }
        return ++k;
    }
};