class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ni) {
        vector<vector<int>> ans;
        for(auto &it : intervals){
            if(it[0]>ni[1]){
                ans.push_back(ni);
                ni = it;
            }else if(it[1]<ni[0]){
                ans.push_back(it);
            }else{
                ni[0] = min(ni[0],it[0]);
                ni[1] = max(ni[1],it[1]);
            }
        }
        ans.push_back(ni);
        return ans;
    }
};
