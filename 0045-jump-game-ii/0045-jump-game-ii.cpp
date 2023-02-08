class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int currMax = 0, jumps = 0, currEnd = 0;
        for(int i=0;i<n;i++){
            currMax = max(currMax,i+nums[i]);
            if(i==currEnd and i!=n-1){
                jumps++;
                currEnd = currMax;
            }
        }
        return jumps;
    }
};