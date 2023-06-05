class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int n = c.size();
        
        double pre_slope = 0.0;
        for(int i=0;i<n-1;i++){
            double y = c[i+1][1]-c[i][1];
            double x = c[i+1][0]-c[i][0];
            pre_slope = x!=0?y/x:INT_MAX;
            for(int j=i+2;j<n;j++){
                double y1 = c[j][1]-c[i][1];
                double x1 = c[j][0]-c[i][0];
                double slope = x1!=0?y1/x1:INT_MAX;
                if(pre_slope != slope)
                    return false;
            }
        }
        return true;
    }
};