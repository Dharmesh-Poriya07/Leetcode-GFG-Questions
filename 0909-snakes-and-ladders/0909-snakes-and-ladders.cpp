class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& b) {
        int n = b.size();
        vector<int> board(n*n,-1);
        for(int i=n-1,cnt=0;0<=i and cnt<board.size();i--){
            for(int j=0;j<n;j++){
                if(-1!=b[i][j])
                    board[cnt] = b[i][j]-1;
                cnt++;
            }
            i--;
            for(int j=n-1;0<=j and cnt<board.size();j--){
                if(-1!=b[i][j])
                    board[cnt] = b[i][j]-1;
                cnt++;
            }
        }
        
        vector<int> distance(n*n,INT_MAX);
        queue<int> q;
        q.push(0);
        distance[0] = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i=1;i<=6 and curr+i<board.size();i++){
                int next = -1==board[curr+i]?curr+i:board[curr+i];
                if(INT_MAX==distance[next]){
                    distance[next] = distance[curr]+1;
                    q.push(next);
                }
            }
        }
        return INT_MAX==distance[n*n-1]?-1:distance[n*n-1];
    }
};