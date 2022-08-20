class Solution {
public:
    string addStrings(string x, string y) {
        string sum = "";
        int endx = x.size()-1,endy = y.size()-1;
        int carry = 0;
        while(0<=endx || 0<=endy){
            int digit = carry;
            if(0<=endx)
                digit += (x[endx--]-'0');
            
            if(0<=endy)
                digit += (y[endy--]-'0');
            
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