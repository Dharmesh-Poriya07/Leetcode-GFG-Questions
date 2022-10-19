//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> x, vector<int> y, int m, int n){
        sort(x.begin(),x.end(),greater<int>());
        sort(y.begin(),y.end(),greater<int>());
        int hcount,vcount;
        hcount = vcount = 1;
        int i=0,j=0;
        int ans = 0;
        m--;
        n--;
        while(i<m and j<n){
            if(x[i]>y[j]){
                ans += x[i++]*hcount;
                vcount ++;
            }else{
                ans += y[j++]*vcount;
                hcount ++;
            }
        }
        while(i<m){
            ans += x[i++]*hcount;
            vcount ++;
        }
        while(j<n){
            ans += y[j++]*vcount;
            hcount ++;
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends