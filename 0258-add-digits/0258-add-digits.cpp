class Solution {
private:
    int sumOfDigits(int num) {
        int sum = 0;
        while(0<num){
            sum += (num%10);
            num /= 10;
        }
        return sum;
    }
public:
    int addDigits(int num) {
        while(num>=10){
            num = sumOfDigits(num);
        }
        return num;
    }
};