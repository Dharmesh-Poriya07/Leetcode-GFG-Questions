//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        int ans = 0;
        sort(a,a+n);
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[a[i]]++;
        }
        for(int i=n-1;0<=i;i--){
            if(0<m[a[i]]){
                ans += m[a[i]]*a[i];
                if(m[a[i]] >= m[a[i]-1]){
                    m[a[i]-1] = 0;
                }else{
                    m[a[i]-1] -= m[a[i]];
                }
                m[a[i]] = 0;
            }
        }
        return ans;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends