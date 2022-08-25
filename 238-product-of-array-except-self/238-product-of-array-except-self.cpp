class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int preproduct = nums[0];
        int suffproduct = nums[n-1];
        ans[0] = ans[n-1] = 1;
        for(int i=1;i<n;i++){
            ans[i] = preproduct;
            preproduct *= nums[i];
        }
        for(int i=n-2;0<=i;i--){
            ans[i] *= suffproduct;
            suffproduct *= nums[i];
        }
        return ans;
    }
};