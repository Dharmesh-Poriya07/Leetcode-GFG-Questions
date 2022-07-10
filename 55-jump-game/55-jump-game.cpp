class Solution {
public:
    bool canJump(vector<int>& nums) {
        int req = 1;
        for(int i=nums.size()-2;0<=i;i--){
            if(nums[i]<req)
                req ++;
            else
                req = 1;
        }
        return 1==req;
    }
};