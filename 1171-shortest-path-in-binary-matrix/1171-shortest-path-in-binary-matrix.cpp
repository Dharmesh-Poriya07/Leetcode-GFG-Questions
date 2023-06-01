class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(1==grid[0][0] || 1==grid[n-1][n-1])
            return -1;
        
        queue<vector<int>> q;
        q.push({0,0,1}); // row,col,path
        
        vector<vector<int>> directions(8);
        directions[0] = {0,1};
        directions[1] = {1,1};
        directions[2] = {1,0};
        directions[3] = {1,-1};
        directions[4] = {0,-1};
        directions[5] = {-1,-1};
        directions[6] = {-1,0};
        directions[7] = {-1,1};
        
        while(!q.empty()){
            vector<int> point = q.front();
            q.pop();
            
            if(n-1==point[0] && n-1==point[1])
                return point[2];
            
            for(auto dire : directions){
                int row = point[0]+dire[0];
                int col = point[1]+dire[1];
                
                if(0<=row && 0<=col && row<n && col<n && 0==grid[row][col]){
                    q.push({row,col,point[2]+1});
                    grid[row][col] = 1;
                }
            }
        }
        return -1;
    }
};