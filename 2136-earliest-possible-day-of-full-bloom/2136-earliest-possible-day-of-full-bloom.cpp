class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> pg;
        for(int i=0;plantTime.size()>i;i++)
            pg.push_back({growTime[i],plantTime[i]});
        
        sort(pg.begin(),pg.end(),greater<pair<int,int>>());
        int bloomDays = 0;
        int seedPlantDays = 0;
        for(int i=0;pg.size()>i;i++){
            int pt = pg[i].second;
            int gt = pg[i].first;
            bloomDays = max(bloomDays,seedPlantDays+pt+gt);
            seedPlantDays += pt;
        }
        return bloomDays;
    }
};