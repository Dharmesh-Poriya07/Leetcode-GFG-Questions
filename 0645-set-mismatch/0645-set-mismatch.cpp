class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        vector<int> mp(nums.size()+1,0);
        for(int n : nums){
            if(0<mp[n]){
                ans.push_back(n);
            }
            mp[n]++;
        }
        for(int i=1;nums.size()>=i;i++){
            if(0==mp[i]){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};