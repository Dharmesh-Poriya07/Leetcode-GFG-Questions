class Solution {
private:
    void dfs(vector<vector<char>>& grid,int row,int col){
        if(grid.size()==row || grid[0].size()==col || -1==row || -1==col || '0'==grid[row][col])
            return;
        
        grid[row][col] = '0';
        
        dfs(grid,row-1,col);
        dfs(grid,row,col+1);
        dfs(grid,row+1,col);
        dfs(grid,row,col-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for(int i=0;grid.size()>i;i++){
            for(int j=0;grid[0].size()>j;j++){
                if('1'==grid[i][j]){
                    islands ++;
                    dfs(grid,i,j);
                }
            }
        }
        return islands;
    }
};