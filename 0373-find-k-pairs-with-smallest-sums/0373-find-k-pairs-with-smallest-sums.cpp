class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minh;
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>> ans;
        set<pair<int,int>> s;
        minh.push({nums1[0]+nums2[0],{0,0}});
        s.insert({0,0});
        
        while(k-- and !minh.empty()){
            auto i = minh.top().second.first;
            auto j = minh.top().second.second;
            minh.pop();
            ans.push_back({nums1[i],nums2[j]});

            if(i+1<n and s.find({i+1,j})==s.end()){
                minh.push({nums1[i+1]+nums2[j],{i+1,j}});
                s.insert({i+1,j});
            } 
            if(j+1<m and s.find({i,j+1})==s.end()){
                minh.push({nums1[i]+nums2[j+1],{i,j+1}});
                s.insert({i,j+1});
            } 
        }
        return ans;
    }
};