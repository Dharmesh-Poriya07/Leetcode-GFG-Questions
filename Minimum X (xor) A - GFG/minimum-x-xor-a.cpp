// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    string binary(int num){
        string ans = "";
        while(0<num){
            ans.push_back('0'+(num&1));
            num >>= 1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int countOnes(string &binary){
        int count = 0;
        for(char ch : binary){
            if('1'==ch)
                count ++;
        }
        return count;
    }
    public:
    int minVal(int a, int b) {
        string bin_a = binary(a);
        string bin_b = binary(b);
        int onesb = countOnes(bin_b);
        int i=0;
        while(i<bin_a.size()){
            if(0<onesb && '1'==bin_a[i]){
               onesb --;
            }else{
                bin_a[i] = '0';
            }
                
            i++;
        }
        // cout<<bin_a<<" "<<onesb<<endl;
        if(0<onesb){
            reverse(bin_a.begin(),bin_a.end());
            int j=0;
            if(bin_a.size()>=countOnes(bin_b)){
                while(true){
                    if('0'==bin_a[j]){
                       bin_a[j] = '1'; 
                       onesb--;
                    }
                    if(0==onesb) break;
                    j++;
                }
            }
            int k=0;
            while(k<bin_a.size()){
                if(0!=onesb && '0'==bin_a[k]){
                    bin_a[k] = '1';
                    onesb--;
                }
                k++;
            }
            while(onesb--){
                bin_a.push_back('1');
            }
            reverse(bin_a.begin(),bin_a.end());
        }
        reverse(bin_a.begin(),bin_a.end());
        int x = 0;
        int power = 0;
        for(char ch : bin_a){
            if('1'==ch){
                x += pow(2,power);
            }
            power ++;
        }
        return x;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends