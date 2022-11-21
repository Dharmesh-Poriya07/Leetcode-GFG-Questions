class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>> q;
        int row = maze.size();
        int col = maze[0].size();
        vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        maze[entrance[0]][entrance[1]] = '+';
        q.push({entrance[0],entrance[1],1});
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            level ++;
            while(sz--){
                auto pos = q.front();
                q.pop();
                for(auto d : dir){
                    int r = pos[0]+d[0];
                    int c = pos[1]+d[1];
                    if(0<=r and 0<=c and row>r and col>c){
                        if('+'!=maze[r][c]){
                            if(0==r or 0==c or row-1==r or col-1==c) return level;
                            q.push({r,c,pos[2]+1});
                            maze[r][c] = '+';
                        }
                    }
                }
            }
        }
        return -1;
    }
};