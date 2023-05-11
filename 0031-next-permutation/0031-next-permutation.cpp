class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1; // it's index where we find there exist greater element in [ind+1,n] range.
        int n = nums.size();
        
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind = i;
                break;
            }
        }
        
        if(-1 == ind){
            reverse(begin(nums),end(nums));
            return;
        }
        
        for(int i=n-1;i>ind;i--){
            if(nums[i] > nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        
        reverse(begin(nums)+ind+1,end(nums));
        return;
    }
};