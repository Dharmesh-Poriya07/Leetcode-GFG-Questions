//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> board)
    {
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
        return board;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends