class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int dup = 0, missing;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0){
                dup = abs(nums[i]);
            }else{
                nums[abs(nums[i])-1] *= (-1);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                missing = i+1;
                break;
            }
        }
        return dup;
    }
};