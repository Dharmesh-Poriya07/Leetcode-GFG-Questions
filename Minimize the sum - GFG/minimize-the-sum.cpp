//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        priority_queue <int, vector<int>, greater<int>> pq(arr.begin(),arr.end());
        int sum = 0;
        while(1<pq.size()){
            int n1 = pq.top();
            pq.pop();
            int n2 = pq.top();
            pq.pop();
            sum += (n1+n2);
            pq.push(n1+n2);
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends