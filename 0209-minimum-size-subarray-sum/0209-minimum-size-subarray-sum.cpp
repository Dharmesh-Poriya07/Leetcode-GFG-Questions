class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int prefix_sum = 0, min_window = n+1, i=0,j=0;
        while(j<n){
            prefix_sum += nums[j];
            while(i<n and prefix_sum >= target){
                min_window = min(min_window,j-i+1);
                prefix_sum -= nums[i];
                i++;
            }
            j++;
        }
        return min_window!=n+1?min_window:0;
    }
};