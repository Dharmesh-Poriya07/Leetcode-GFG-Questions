class Solution {
private:
    int binLength(int i){
        int count = 0;
        while(0<i){
            count ++;
            i >>= 1;
        }
        return count;
    }
public:
    int concatenatedBinary(int n) {
        int mod = 1000000007;
        long ans = 0;
        for(int i=1;i<=n;i++){
            int length = binLength(i);
            
            ans = ((ans << length) + i)%mod;
        }
        return ans;
    }
};