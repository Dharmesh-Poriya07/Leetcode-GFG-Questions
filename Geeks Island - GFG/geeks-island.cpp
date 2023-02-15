//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int water_flow(vector<vector<int>> &mat,int n,int m){
        vector<vector<bool>> io(n,vector<bool>(m,false));
        vector<vector<bool>> as(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            io[i][0] = true;
            q.push({i,0});
        }
        for(int j=0;j<m;j++){
            io[0][j] = true;
            q.push({0,j});
        }
        
        vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            auto current = q.front();
            q.pop();
            for(auto d : dir){
                int i = d[0]+current.first;
                int j = d[1]+current.second;
                if(i!=n and j!=m and -1!=i and -1!=j and !io[i][j] and mat[i][j]>=mat[current.first][current.second]){
                    io[i][j] = true;
                    q.push({i,j});
                }
            }
        }
        for(int i=0;i<n;i++){
            as[i][m-1] = true;
            q.push({i,m-1});
        }
        for(int j=0;j<m;j++){
            as[n-1][j] = true;
            q.push({n-1,j});
        }
        
        while(!q.empty()){
            auto current = q.front();
            q.pop();
            for(auto d : dir){
                int i = d[0]+current.first;
                int j = d[1]+current.second;
                if(i!=n and j!=m and -1!=i and -1!=j and !as[i][j] and mat[i][j]>=mat[current.first][current.second]){
                    as[i][j] = true;
                    q.push({i,j});
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(io[i][j] and as[i][j]){
                    ans ++;
                }
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends