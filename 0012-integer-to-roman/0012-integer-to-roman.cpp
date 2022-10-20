class Solution {
public:
    string intToRoman(int num) {
        vector<int> value = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> roman_char = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string result = "";
        for(int i=0;i<13;i++){
            int q = num/value[i];
            num %= value[i];
            while(q--)
                result += roman_char[i];
        }
        return result;
    }
};