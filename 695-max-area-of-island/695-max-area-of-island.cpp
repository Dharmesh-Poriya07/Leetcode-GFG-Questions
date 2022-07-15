class Solution {
private:
    int dfs(vector<vector<int>>& grid,int row,int col){
        if(-1==row || -1==col || grid.size()==row || grid[0].size()==col || 0==grid[row][col] || 2==grid[row][col]){
            return 0;
        }
        
        grid[row][col] = 2;
        int left = dfs(grid,row,col-1);
        int right = dfs(grid,row,col+1);
        int top = dfs(grid,row-1,col);
        int bottom = dfs(grid,row+1,col);
        
        return 1+left+right+top+bottom;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        for(int i=0;grid.size()>i;i++){
            for(int j=0;grid[0].size()>j;j++){
                if(2!=grid[i][j] || 0!=grid[i][j]){
                    int temp = dfs(grid,i,j);
                    // cout<<temp<<"->"<<i<<"->"<<j<<endl;
                    maxarea = max(maxarea,temp);
                }
            }
        }
        return maxarea;
    }
};