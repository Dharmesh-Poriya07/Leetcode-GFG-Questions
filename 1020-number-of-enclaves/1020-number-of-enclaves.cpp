class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ones = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        queue<vector<int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if((0==i or 0==j or rows-1==i or cols-1==j) and 1==grid[i][j]){
                    grid[i][j] = 2;
                    q.push({i,j});
                }
                if(grid[i][j]) ones++;
            }
        }
        ones -= q.size();
        vector<int> directions[] = {{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            for(auto d : directions){
                int nr = curr[0]+d[0];
                int nc = curr[1]+d[1];
                if(0<nr and 0<nc and rows>nr and cols>nc and 1==grid[nr][nc]){
                    grid[nr][nc] = 2;
                    ones--;
                    q.push({nr,nc});
                }
            }
        }
        return ones;
    }
};