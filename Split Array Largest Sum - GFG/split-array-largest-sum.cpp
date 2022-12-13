//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int sumSubarrayWithMid(vector<int> &nums,int mid){
        int count=1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>mid){
                count ++;
                sum = nums[i];
            }else sum += nums[i];
        }
        return count;
    }
  public:
    int splitArray(int arr[] ,int N, int k) {
        vector<int> nums(arr,arr+N);
        int low = *(max_element(nums.begin(),nums.end()));
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = low;
        while(low<=high){
            int mid = low + (high-low)/2;
            int n = sumSubarrayWithMid(nums,mid);
            if(n>k) low = mid+1;
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends