class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i]) cnt += nums[i];
            else cnt = 0;
            mx = max(mx,cnt);
        }
        return mx;
    }
};