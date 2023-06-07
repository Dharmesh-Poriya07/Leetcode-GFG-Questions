class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while(a>0 or b>0 or c>0){
            bool bit_a,bit_b,bit_c;
            bit_a = (a&1);
            bit_b = (b&1);
            bit_c = (c&1);

            a >>= 1;
            b >>= 1;
            c >>= 1;

            if(bit_c != (bit_a|bit_b)){
                if(!bit_c and (bit_a and bit_b)){
                    flips += 2;
                }else{
                    flips++;
                }
            }
        }
        return flips;
    }
};