class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        map<int,int> mp;
        for(int n : nums){
            if(1==mp[n]){
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