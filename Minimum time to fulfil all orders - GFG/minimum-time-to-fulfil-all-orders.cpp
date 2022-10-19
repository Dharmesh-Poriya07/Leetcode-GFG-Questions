//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
    private:
    bool isPossible(int n,vector<int> &rank,int l,int mid){
        int cnt = 0;
        
        for(int i=0;i<l;i++){
            int c = 0;
            int time = mid;
            int prep = rank[i];
            while(0<time){
                time -= prep;
                if(0<=time){
                    c++;
                    prep += rank[i];
                }
            }
            cnt += c;
            if(cnt>=n)
                return true;
        }
        return false;
    }
    public:
    int findMinTime(int N, vector<int>&A, int L){
        int low = 0;
        int high = 1e6+7;
        int mid,ans=-1;
        
        while(low<=high){
            mid = low + (high-low)/2;
            if(isPossible(N,A,L,mid)){
                ans = mid;
                high = mid-1;
            }else
                low = mid+1;
            
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
	    int n;
	    cin >> n;
	    int l;
	    cin >> l;
	    vector<int>arr(l);
	    for(int i = 0; i < l; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    int ans = ob.findMinTime(n, arr, l);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends