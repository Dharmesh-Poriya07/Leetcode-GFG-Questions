class Solution {
public:
    int getValue(char symbol){
        switch(symbol){
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int ans = 0;
        int len = s.size();
        if(1==len){
            return getValue(s[0]);
        }
        for(int i=len-1;i>0;i--){
            int val1 = getValue(s[i]);
            int val2 = getValue(s[i-1]);
            if(val2<val1){
                ans += val1-val2;
                i--;
            }else{
                ans += val1;
            }
        }
        if(getValue(s[0])>=getValue(s[1])){
            ans += getValue(s[0]);
        }
        return ans;
    }
};