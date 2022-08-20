class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0;
        int currentFuel = startFuel;
        priority_queue<pair<int,int>> hypo;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto st : stations){
            pq.push({st[0],st[1]});
        }
        while(currentFuel<target){
            while(!pq.empty() && pq.top().first<=currentFuel){
                hypo.push({pq.top().second,pq.top().first});
                pq.pop();
            }
            if(currentFuel<target && !hypo.empty()){
                currentFuel += hypo.top().first;
                hypo.pop();
                stops ++;
            }else{
                stops = -1;
                break;
            }
            // cout<<currentFuel<<endl;
        }
        return stops;
    }
};