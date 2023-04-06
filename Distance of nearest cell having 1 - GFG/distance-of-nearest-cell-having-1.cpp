//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> ans(n,vector<int>(m,-1));
	    queue<vector<int>> q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(1==grid[i][j]){
	                q.push({i,j,0});
	                grid[i][j] = 2;
	            }
	        }
	    }
	    vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
	    while(!q.empty()){
	        auto curr = q.front(); q.pop();
	        ans[curr[0]][curr[1]] = curr[2];
	        
	        for(auto d : dir){
	            int nr = d[0]+curr[0];
	            int nc = d[1]+curr[1];
	            if(0<=nr and 0<=nc and nr<n and nc<m and 2!=grid[nr][nc]){
	                q.push({nr,nc,1+curr[2]});
	                grid[nr][nc] = 2;
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends