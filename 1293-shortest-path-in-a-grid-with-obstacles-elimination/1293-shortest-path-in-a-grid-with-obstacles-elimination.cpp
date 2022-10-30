class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int steps = 0;
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<vector<int>>> v(m,vector<vector<int>>(n,vector<int>(k+1,false)));
        queue<vector<int>> q;
        q.push({0,0,k});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr = q.front();
                q.pop();
                if(curr[0]==m-1 and curr[1]==n-1)
                    return steps;
                
                for(auto d : dir){
                    int i = curr[0]+d[0];
                    int j = curr[1]+d[1];
                    int obs = curr[2];
                    
                    if(i>=0 and i<m and j>=0 and j<n){
                        if(grid[i][j]==0 and !v[i][j][obs]){
                            q.push({i,j,obs});
                            v[i][j][obs] = true;
                        }else if(grid[i][j]==1 and obs>0 and !v[i][j][obs-1]){
                            q.push({i,j,obs-1});
                            v[i][j][obs-1] = true;
                        }
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};