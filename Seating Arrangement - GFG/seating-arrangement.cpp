//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        if(1==m){
            if((seats[0]==1 and n>0) or n>1){
                return false;
            }
            return (seats[0]==0 and n<=1)or(0==n);
        }
        for(int i=0;i<m;i++){
            if(1==seats[i]) continue;
            if(0==i){
                if(i+1<m and seats[i+1]!=1){
                    seats[i] = 1;
                    n--;
                }
            }else if(m-1==i){
                if(i-1>=0 and seats[i-1]!=1){
                    seats[i] = 1;
                    n--;
                }
            }else{
                if(1!=seats[i-1] and 1!=seats[i+1]){
                    seats[i] = 1;
                    n--;
                }
            }
        }
        return n<=0;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends