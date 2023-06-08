class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        int r=m-1,c=0;
        while(0<=r and c<n){
            if(0>grid[r][c]){
                count += (n-c);
                r--;
            }else{
                c++;
            }
        }
        return count;
    }
};