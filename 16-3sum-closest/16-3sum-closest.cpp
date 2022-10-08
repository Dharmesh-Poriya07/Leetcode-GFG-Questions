class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int threesum = 0, closest = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int low=0;
            int high = nums.size()-1;
            while(low<high){
                if(i==low){
                    low ++;
                    continue;
                }else if(i==high){
                    high --;
                    continue;
                }
                int csum = nums[i]+nums[low]+nums[high];
                if(csum<target) low ++;
                else high --;
                if(abs(csum-target)<closest){
                    closest = abs(csum-target);
                    threesum = csum;
                }
            }
        }
        return threesum;
    }
};