class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(1==points.size()) return 1;
        int ans = 0;
        for(int i=0;i<points.size();i++){
            unordered_map<int,int> m1;
            m1[i]++;
            for(int j=i+1;j<points.size();j++){
                if(1==m1[j]) continue;
                m1[j]++;
                double slope = (points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                int prev = j;
                unordered_map<int,int> m;
                m[i]++;
                m[j]++;
                int count = 2;
                for(int k=j+1;k<points.size();k++){
                    if(1==m[k]) continue;
                    double s1 = (points[j][1]-points[k][1])/(double)(points[j][0]-points[k][0]);
                    double s2 = (points[k][1]-points[j][1])/(double)(points[k][0]-points[j][0]);
                    if(s1==slope){
                        count++;
                        m[k]++;                        
                    }else if(s2==slope){
                        count++;
                        m[k]++;
                    } 
                }
                ans = max(count,ans);
            }
        }
        return ans;
    }
};