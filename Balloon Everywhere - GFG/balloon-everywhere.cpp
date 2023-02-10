//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        unordered_map<char,int> freq;
        for(char ch : s){
            freq[ch]++;
        }
        int tb = freq['b'];
        int ta = freq['a'];
        int tl = freq['l'];
        int to = freq['o'];
        int tn = freq['n'];
        return min(tn,min(min(tb,ta),min(to/2,tl/2)));
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends