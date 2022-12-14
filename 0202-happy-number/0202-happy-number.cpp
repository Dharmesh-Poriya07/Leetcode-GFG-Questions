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
        unordered_set<int> m;
        while(m.end()==m.find(n)){
            m.insert(n);
            n = digitSquare(n);
            if(1==n) return true;
        }
        return false;
    }
};