class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size(), m = version2.size();
        int i=0,j=0;
        while(i<n or j<m){
            string r1 = "", r2 = "";
            while(i<n and version1[i]!='.'){
                r1.push_back(version1[i]);
                i++;
            }
            while(j<m and version2[j]!='.'){
                r2.push_back(version2[j]);
                j++;
            }
            int r11 = r1.size()>0?stoi(r1):0;
            int r22 = r2.size()>0?stoi(r2):0;
            if(r11<r22){
                return -1;
            }else if(r11>r22){
                return 1;
            }
            i++;
            j++;
        }
        return 0;
    }
};