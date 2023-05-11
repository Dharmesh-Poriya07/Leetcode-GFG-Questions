//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int nums[], int n)
    {
        int low,mid,high;
        low = mid = 0;
        high = n-1;
        
        while(mid <= high){
            if(0==nums[mid]){
                swap(nums[low],nums[mid]);
                mid ++;
                low ++;
            }else if(1 == nums[mid]){
                mid ++;
            }else{
                swap(nums[mid],nums[high]);
                high --;
            }
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends