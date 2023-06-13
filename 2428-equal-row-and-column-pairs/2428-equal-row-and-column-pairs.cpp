class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                bool flag = false;
                for(int ki=0,kj=0;ki<n;ki++,kj++){
                    if(grid[ki][j] != grid[i][kj]){
                        flag = true;
                        break;
                    }
                }
                if(!flag) ans++;
            }
        }
        return ans;
    }
};