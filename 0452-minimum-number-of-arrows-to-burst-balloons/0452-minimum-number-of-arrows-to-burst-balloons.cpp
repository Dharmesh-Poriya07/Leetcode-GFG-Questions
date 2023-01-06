class Solution {
private:
    static bool myCmp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),myCmp);
        int ans = 0;
        int pmn = points[0][1];
        for(int i=1;i<points.size();i++){
            if(pmn>=points[i][0]){
                pmn = min(pmn,points[i][1]);
            }else{
                pmn = points[i][1];
                ans ++;
            }
        }
        ans++;
        return ans;
    }
};