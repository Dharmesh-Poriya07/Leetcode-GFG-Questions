// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        sort(arr,arr+n);
        long long num1,num2;
        num1=num2=0;
        for(int i=0;i<n;i+=2){
            num1 *= 10;
            num1 += arr[i];
        }
        for(int i=1;i<n;i+=2){
            num2 *= 10;
            num2 += arr[i];
        }
        long long ans = num1+num2;
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends