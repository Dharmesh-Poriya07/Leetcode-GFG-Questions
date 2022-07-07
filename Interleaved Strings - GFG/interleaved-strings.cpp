// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    int helper(string &s1,string &s2,string &s3,int i,int j,vector<vector<int>> &dp){
        if(s1.size()==i && s2.size()==j) return 1;
        
        if(-1!=dp[i][j]) return dp[i][j];
        
        if(s1.size()>i && s1[i]==s3[i+j]){
            dp[i][j] = helper(s1,s2,s3,i+1,j,dp);
            if(1==dp[i][j]){
                return 1;
            }
        }
        
        if(s2.size()>j && s2[j]==s3[i+j]){
            dp[i][j] = helper(s1,s2,s3,i,j+1,dp);
            if(1==dp[i][j]){
                return 1;
            }
        }
        
        return dp[i][j] = 0;
    }
  public:
    /*You are required to complete this method */
    bool isInterleave(string s1, string s2, string s3) 
    {
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return helper(s1,s2,s3,0,0,dp);
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends