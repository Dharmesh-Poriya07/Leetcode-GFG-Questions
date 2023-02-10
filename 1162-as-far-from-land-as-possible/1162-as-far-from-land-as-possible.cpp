class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<vector<int>> q;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(1==grid[i][j])
                    q.push({i,j,0}),vis[i][j]=true;
        
        int mxdist = INT_MIN;
        vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            auto cell = q.front();
            q.pop();
            vis[cell[0]][cell[1]] = true;
            for(auto d : dir){
                int i = d[0]+cell[0];
                int j = d[1]+cell[1];
                if(0<=i and 0<=j and i<n and j<n and !vis[i][j]){
                    if(0==grid[i][j]){
                        mxdist = max(mxdist,cell[2]+1);
                    }
                    vis[i][j] = true;
                    q.push({i,j,cell[2]+1});
                }
            }
        }
        return mxdist==INT_MIN?-1:mxdist;
    }
};