// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void prin(int i,int j,vector<vector<int>> brackets,char &name,string &ans){
       if(i+1==j){
           ans=ans+name;
           name++;
           return ;
       }
       ans=ans+'(';
       int k=brackets[i][j];
       prin(i,k,brackets,name,ans);
       prin(k,j,brackets,name,ans);
       ans=ans+')';
       return ;
   }
public:
    string matrixChainOrder(int a[], int n){
        
        vector<vector<int>> dp(n,vector<int>(n));
       vector<vector<int>> brackets(n,vector<int>(n));
       for(int i=0;i<n-1;i++){
           dp[i][i+1]=0;
       }
       for(int gap=2;gap<n;gap++){
           for(int i=0;i+gap<n;i++){
               int j=i+gap;
               dp[i][j]=INT_MAX;
               for(int k=i+1;k<j;k++){
                   int q=dp[i][k]+dp[k][j]+a[i]*a[k]*a[j];
                   if(q<dp[i][j]){
                       dp[i][j]=q;
                       brackets[i][j]=k;
                   }
               }
           }
       }
       char name='A';
       string ans="";
       prin(0,n-1,brackets,name,ans);
       return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends