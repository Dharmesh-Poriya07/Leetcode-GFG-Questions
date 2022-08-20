class Solution {
public:
    string addStrings(string num1, string num2) {
        string sum = "";
        int endnum1 = num1.size()-1,endnum2 = num2.size()-1;
        int carry = 0;
        while(0<=endnum1 || 0<=endnum2){
            int digit = carry;
            if(0<=endnum1)
                digit += (num1[endnum1--]-'0');
            
            if(0<=endnum2)
                digit += (num2[endnum2--]-'0');
            
            carry = digit/10;
            sum.push_back('0'+digit%10);
        }
        if(0<carry){
            sum.push_back('0'+carry);
        }
        reverse(sum.begin(),sum.end());
        return sum;
    }
};