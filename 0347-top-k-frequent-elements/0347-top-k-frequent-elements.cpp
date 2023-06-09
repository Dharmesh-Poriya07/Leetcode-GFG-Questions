class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int num : nums) freq[num]++;

        vector<vector<int>> bucket(n+1);
        for(auto [num, f] : freq){
            bucket[f].push_back(num);
        }

        vector<int> ans;
        for(int i=n;i>=0 and k>0;i--){
            while(bucket[i].size() > 0){
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return ans;
    }
};