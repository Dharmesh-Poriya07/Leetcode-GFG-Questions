class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> ones1;
        vector<pair<int,int>> ones2;
        
        int ans = 0;
        for(int i=0;i<img1.size();i++){
            for(int j=0;j<img2.size();j++){
                if(1==img1[i][j])
                    ones1.push_back({i,j});
                if(1==img2[i][j])
                    ones2.push_back({i,j});
            }
        }
        map<pair<int,int>,int> mp;
        for(auto [i1,j1] : ones1){
            for(auto [i2,j2] : ones2){
                mp[{i2-i1,j2-j1}]++;
                ans = max(ans,mp[{i2-i1,j2-j1}]);
            }
        }
        return ans;
    }
};