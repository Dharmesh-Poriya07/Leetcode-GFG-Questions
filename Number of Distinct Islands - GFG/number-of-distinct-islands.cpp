//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>> s;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> directions[] = {{-1,0},{0,1},{1,0},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(1==grid[i][j]){
                    queue<vector<int>> q;
                    vector<int> dim = {i,j};
                    vector<pair<int,int>> temp;
                    temp.push_back({0,0});
                    q.push(dim);
                    grid[i][j] = 2;
                    while(!q.empty()){
                        auto curr = q.front(); q.pop();
                        temp.push_back({curr[0]-dim[0],curr[1]-dim[1]});
                        for(auto d : directions){
                            int nr = curr[0]+d[0];
                            int nc = curr[1]+d[1];
                            if(0<=nr and 0<=nc and n>nr and m>nc and 1==grid[nr][nc]){
                                q.push({nr,nc});
                                grid[nr][nc] = 2;
                            }
                        }
                    }
                    s.insert(temp);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends