class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=1;i<grid.size()-1;i++)
            for(int j=1;j<grid[0].size()-1;j++)
                if(0==grid[i][j])
                    ans += dfs(grid,i,j);
        return ans;
    }
    
    bool dfs(vector<vector<int>>& grid,int i,int j){
        int rows = grid.size();
        int cols = grid[0].size();
        if(0>i or 0>j or rows<=i or cols<=j) return false;
        
        if(1==grid[i][j] or 2==grid[i][j]) return true;
        
        grid[i][j] = 2;
        bool top = dfs(grid,i-1,j);
        bool right = dfs(grid,i,j+1);
        bool bottom = dfs(grid,i+1,j);
        bool left = dfs(grid,i,j-1);
        
        return (top and right and bottom and left);
    }
};