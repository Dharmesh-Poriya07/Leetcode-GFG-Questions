//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    void dfs(vector<vector<char>>& grid,int row,int col){
        if(grid.size()==row || grid[0].size()==col || -1==row || -1==col || '0'==grid[row][col])
            return;
        
        grid[row][col] = '0';
        
        dfs(grid,row-1,col);
        dfs(grid,row-1,col+1);
        dfs(grid,row,col+1);
        dfs(grid,row+1,col+1);
        dfs(grid,row+1,col);
        dfs(grid,row+1,col-1);
        dfs(grid,row,col-1);
        dfs(grid,row-1,col-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for(int i=0;grid.size()>i;i++){
            for(int j=0;grid[0].size()>j;j++){
                if('1'==grid[i][j]){
                    islands ++;
                    dfs(grid,i,j);
                }
            }
        }
        return islands;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends