class Solution {
    void findIslands(vector<vector<int>>& grid,int i,int j,vector<pair<int,int>> &temp){
        int n = grid.size();
        vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = 2;
        temp.push_back({i,j});
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            
            for(auto d : dir){
                int x = d[0] + curr.first;
                int y = d[1] + curr.second;
                
                if(x>=0 and y>=0 and x<n and y<n and grid[x][y]==1){
                    grid[x][y] = 2;
                    q.push({x,y});
                    temp.push_back({x,y});
                }
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        vector<vector<pair<int,int>>> islands;
        int n = grid.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(1==grid[i][j]){
                    vector<pair<int,int>> temp;
                    findIslands(grid,i,j,temp);
                    islands.push_back(temp);
                }
            }
        }
        
        int flips = INT_MAX;
        for(auto is1 : islands[0]){
            for(auto is2 : islands[1]){
                int dis = abs(is1.first-is2.first)+abs(is1.second-is2.second);
                if(flips > dis){
                    flips = dis;
                }
            }
        }
        return flips-1;
    }
};