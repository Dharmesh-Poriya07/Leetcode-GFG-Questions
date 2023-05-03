class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hm1,hm2;
        for(int ni : nums1) hm1[ni]++;
        for(int ni : nums2) hm2[ni]++;
        vector<vector<int>> ans(2);
        for(auto [ni,val] : hm1){
            if(0==hm2[ni]) ans[0].push_back(ni);
        }
        for(auto [ni,val] : hm2){
            if(0==hm1[ni]) ans[1].push_back(ni);
        }
        return ans;
    }
};