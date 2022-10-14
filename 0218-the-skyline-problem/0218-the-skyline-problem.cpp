class Solution {
private:
    static bool myCmp(pair<int,int> &a,pair<int,int> &b){
        if(a.first == b.first)
            return a.second<b.second;
        return a.first<b.first;
    }
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> points;
        int ch = 0; // current height
        multiset<int> pq;
        pq.insert(0);
        vector<vector<int>> ans;
        for(auto b : buildings){
            points.push_back({b[0],0-b[2]});
            points.push_back({b[1],b[2]});
        }
        sort(points.begin(),points.end(),myCmp);
        
        for(int i=0;points.size()>i;i++){
            if(0 > points[i].second){
                pq.insert(0-points[i].second);
                auto it = pq.rbegin();
                if(ch < *it){
                    ch = *it;
                    ans.push_back({points[i].first,ch});
                }
            }else{
                pq.erase(pq.find(points[i].second));
                auto it = pq.rbegin();
                if(ch != *it){
                    ch = *it;
                    ans.push_back({points[i].first,ch});
                }
            }
        }
        return ans;
    }
};