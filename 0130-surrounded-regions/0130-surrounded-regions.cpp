class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((0==i or 0==j or n-1==i or m-1==j) and 'O'==board[i][j]){
                    q.push({i,j});
                    board[i][j] = '#';
                }
            }
        }
        vector<int> directions[] = {{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            for(auto d : directions){
                int nr = curr[0]+d[0];
                int nc = curr[1]+d[1];
                if(0<nr and 0<nc and n>nr and m>nc and 'O'==board[nr][nc]){
                    q.push({nr,nc});
                    board[nr][nc] = '#';
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if('O'==board[i][j]) board[i][j] = 'X';
                if('#'==board[i][j]) board[i][j] = 'O';
            }
        }
    }
};