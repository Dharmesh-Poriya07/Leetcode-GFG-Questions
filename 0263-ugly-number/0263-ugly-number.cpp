class Solution {
public:
    bool isUgly(int n) {
        if(0==n or 1==n) return n;
        while(0==n%2){
            n /= 2;
        }
        while(0==n%3){
            n /= 3;
        }
        while(0==n%5){
            n /= 5;
        }
        return 1==n;
    }
};