class Solution {
private:
    int getReverse(int num){
        int rev = 0;
        while(0<num){
            rev *= 10;
            rev += (num%10);
            num /= 10;
        }
        return rev;
    }
public:
    int maximum69Number (int num) {
        int revNum = getReverse(num);
        int ans = 0;
        bool flag = false;
        while(0<revNum){
            ans *= 10;
            int rem = revNum%10;
            if(6==rem and !flag){
                rem = 9;
                flag = true;
            }
            ans += rem;
            revNum /= 10;
        }
        return ans;
    }
};