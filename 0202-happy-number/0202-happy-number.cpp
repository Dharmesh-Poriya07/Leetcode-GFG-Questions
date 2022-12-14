class Solution {
int digitSquare(int n){
    int sq = 0;
    while(0<n){
        int last_digit = n%10;
        sq += (last_digit*last_digit);
        n /= 10;
    }
    return sq;
}
public:
    bool isHappy(int n) {
        unordered_map<int,int> m;
        while(0==m[n]){
            m[n]++;
            n = digitSquare(n);
            if(1==n) return true;
        }
        return false;
    }
};