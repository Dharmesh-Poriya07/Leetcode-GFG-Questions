// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    long long mod = 1e9+7;
public:
    
    int FindNthTerm(long long int n) {
        // if(2>n) return 1;
        vector<int> bin;
        int temp = n;
        while(0<temp){
            bin.push_back(temp&1);
            // cout<<bin[0];
            temp >>= 1;
        }
        
        vector<long long> mat = {1,1,1,0};
        vector<vector<long long>> mul(bin.size(),vector<long long>(4));
        
        int bins = bin.size();
        mul[0] = mat;
        for(int i=1;i<bins;i++){
            auto prev = mul[i-1];
            long long e1 = (prev[0]*prev[0] + prev[1]*prev[2])%mod;
            long long e2 = (prev[0]*prev[1] + prev[1]*prev[3])%mod;
            long long e3 = (prev[2]*prev[0] + prev[3]*prev[2])%mod;
            long long e4 = (prev[2]*prev[1] + prev[3]*prev[3])%mod;
            mul[i] = {e1,e2,e3,e4};
            // cout<<i << "=>" <<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
        }
        
        vector<long long> p = {-1,-1,-1,-1};
        bool flag = false;
        vector<long long> finle;
        for(int i=0;i<bin.size();i++){
            if(0==bin[i]) continue;
            if(1==bin[i] && -1!=p[0]){
                long long e1 = (p[0]*mul[i][0] + p[1]*mul[i][2])%mod;
                long long e2 = (p[0]*mul[i][1] + p[1]*mul[i][3])%mod;
                long long e3 = (p[2]*mul[i][0] + p[3]*mul[i][2])%mod;
                long long e4 = (p[2]*mul[i][1] + p[3]*mul[i][3])%mod;
                finle = {e1,e2,e3,e4};
                p = finle;
            }else{
                p = mul[i];
                finle = mul[i];
            }
        }
        
        long long ans = finle[0];
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends