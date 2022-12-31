class Solution {
    int paths;
    void helper(vector<vector<int>>& grid,int sx,int sy,int zeros){
        if(0>sx or 0>sy or grid.size()==sx or grid[0].size()==sy or -1==grid[sx][sy]) return;
        if(2==grid[sx][sy]){
            if(0==zeros) paths++;
            return;
        }
        if(1!=grid[sx][sy]){
            zeros--;
        }
        grid[sx][sy] = -1;
        helper(grid,sx-1,sy,zeros);
        helper(grid,sx,sy+1,zeros);
        helper(grid,sx+1,sy,zeros);
        helper(grid,sx,sy-1,zeros);
        grid[sx][sy] = 0;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        paths = 0;
        int zeros = 0;
        int sx,sy;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(1==grid[i][j]){
                    sx = i,sy=j;
                }else if(0==grid[i][j]){
                    zeros++;
                }
            }
        }
        helper(grid,sx,sy,zeros);
        return paths;
    }
};
