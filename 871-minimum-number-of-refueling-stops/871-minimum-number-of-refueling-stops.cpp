class Solution {
private:
    static bool myCmp(vector<int> &a,vector<int> &b){
        return a[0]<b[0];
    }
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0, currentFuel = startFuel;
        priority_queue<pair<int,int>> hypo;
        sort(stations.begin(),stations.end(),myCmp);
        int i = 0;
        while(currentFuel<target){
            while(stations.size()>i && stations[i][0]<=currentFuel){
                hypo.push({stations[i][1],stations[i][0]});
                i++;
            }
            if(currentFuel<target && !hypo.empty()){
                currentFuel += hypo.top().first;
                hypo.pop();
                stops ++;
            }else{
                stops = -1;
                break;
            }
        }
        return stops;
    }
};