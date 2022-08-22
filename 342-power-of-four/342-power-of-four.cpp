class Solution {
public:
    bool isPowerOfFour(int n) {
        if(INT_MIN==n || 0==n || 2==n) return false;
        if(0==(n&(n-1))){
            n = ceil(sqrt(n));
            return 0==(n&(n-1));
        }
        return false;
    }
};