class Solution {
private:
    int dfs(vector<vector<int>>& grid,int r,int c){
        if(0==c and -1==grid[r][c]) return -1;
        if(grid[0].size()-1==c and 1==grid[r][c]) return -1;
        if(grid.size()-1==r){
            if(1==grid[r][c]) return 1==grid[r][c+1]?c+1:-1;
            if(-1==grid[r][c]) return -1==grid[r][c-1]?c-1:-1;
        }
        
        if(1==grid[r][c])
            return -1!=grid[r][c+1]? dfs(grid,r+1,c+1) : -1;
        return 1!=grid[r][c-1]? dfs(grid,r+1,c-1) : -1;
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size());
        for(int j=0;grid[0].size()>j;j++){
            ans[j] = dfs(grid,0,j);
        }
        return ans;
    }
};