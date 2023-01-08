class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(1==points.size()) return 1;
        int ans = 0;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                double slope = (points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                int count = 2;
                for(int k=j+1;k<points.size();k++){
                    double s1 = (points[j][1]-points[k][1])/(double)(points[j][0]-points[k][0]);
                    double s2 = (points[k][1]-points[j][1])/(double)(points[k][0]-points[j][0]);
                    if(s1==slope)
                        count++;                   
                    else if(s2==slope)
                        count++;
                }
                ans = max(count,ans);
            }
        }
        return ans;
    }
};