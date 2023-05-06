class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int mod = 1e9+7;    
        vector<int> pwerOf2(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            pwerOf2[i] = (pwerOf2[i-1]*2)%mod;
        }
        
        int left = 0,right=nums.size()-1;
        int ans = 0;
        while(left<=right){
            if(nums[left]+nums[right]<=target){
                ans += pwerOf2[right-left];
                ans %= mod;
                left ++;
            }else{
                right --;
            }
        }
        return ans;
    }
};