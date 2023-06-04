class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> f;
        vector<int> ans;
        for(auto i : nums) f[i]++;
        for(auto it : f){
            if(it.second > ceil(n/3))
                ans.push_back(it.first);
        }
        return ans;
    }
};