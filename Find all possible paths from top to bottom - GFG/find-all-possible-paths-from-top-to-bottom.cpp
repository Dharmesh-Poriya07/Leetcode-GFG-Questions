// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
private:
    void helper(int i,int j,int n,int m,vector<int> &temp,vector<vector<int>> &ans,vector<vector<int>> &grid){
        if(i==n || j==m) return;
        
        temp.push_back(grid[i][j]);
        if(i==n-1 && j==m-1){ ans.push_back(temp);temp.pop_back();return;}
        
        helper(i+1,j,n,m,temp,ans,grid);
        helper(i,j+1,n,m,temp,ans,grid);
        temp.pop_back();
        return;
    }
public:
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0,0,n,m,temp,ans,grid);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends