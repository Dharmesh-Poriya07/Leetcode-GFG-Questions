class Solution {
public:
    bool isPowerOfThree(int n) {
        if(0==n || 1==n) return n;
        if(0!=n%3) return false;
        return isPowerOfThree(n/3);
    }
};