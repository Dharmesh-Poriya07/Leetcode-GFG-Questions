class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n),suffix(n);
        prefix[0] = suffix[n-1] = 1;
        
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]*nums[i-1];
        }
        for(int i=n-2;0<=i;i--){
            suffix[i] = suffix[i+1]*nums[i+1];
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(prefix[i]*suffix[i]);
        }
        return ans;
    }
};