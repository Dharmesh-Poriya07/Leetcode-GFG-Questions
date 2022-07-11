// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    sort(a,a+n);
    if(1!=n && a[n-1]==a[0]) return {-1};
    
    vector<int> ans(n);
    for(int i=n-1,j=0;0<=i && j<n;i--,j+=2){
        ans[j] = a[i];
    }
    for(int i=0,j=1;i<n && j<n;i++,j+=2){
        ans[j] = a[i];
    }
    return ans;
}
