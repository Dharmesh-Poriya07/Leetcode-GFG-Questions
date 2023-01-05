class Solution {
    bool static myCmp(vector<int>& a, vector<int>& b) {return a[1] < b[1];}
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), myCmp);
        int ans = 0, arrow = 0;
        for (int i = 0; i < points.size(); i ++) {
            if (ans == 0 or points[i][0] > arrow) {
                ans ++;
                arrow = points[i][1];
            }
        }
        return ans;
    }
};