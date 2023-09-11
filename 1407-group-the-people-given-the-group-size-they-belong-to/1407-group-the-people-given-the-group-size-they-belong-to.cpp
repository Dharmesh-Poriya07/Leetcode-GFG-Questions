class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> group;
        vector<vector<int>> ans;
        
        for(int i = 0; i < groupSizes.size(); ++i) {
            int size = groupSizes[i];
            group[size].push_back(i);
            
            if(group[size].size() == size) {
                ans.push_back(group[size]);
                group[size].clear();
            }
        }
        return ans;
    }
};