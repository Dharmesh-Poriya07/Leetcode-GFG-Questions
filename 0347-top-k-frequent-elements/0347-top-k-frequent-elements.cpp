class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto &n : nums) freq[n]++;
        
        vector<vector<int>> bucket(nums.size()+1);
        for(auto [key,val] : freq){
            bucket[val].push_back(key);
        }
        
        vector<int> ans;
        for(int i=nums.size();i>=0 and k>0;i--){
            if(0 < bucket[i].size()){
                while(bucket[i].size()>0){
                    ans.push_back(bucket[i].back());
                    bucket[i].pop_back();
                    k--;
                }
            }
        }
        
        return ans;
    }
};