class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for(int i=0;i<n;i++){
            int cnt = 0;
            if(1==nums[i]){
                while(i<n and 1==nums[i]){
                    cnt ++;
                    i++;
                }
                mx = max(cnt,mx);
            }
        }
        return mx;
    }
};