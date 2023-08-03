class Solution {
public:
    string digitToString(int d){
        string str;
        switch(d){
            case 2:
                str = "abc";
                break;
            case 3:
                str = "def";
                break;
            case 4:
                str = "ghi";
                break;
            case 5:
                str = "jkl";
                break;
            case 6:
                str = "mno";
                break;
            case 7:
                str = "pqrs";
                break;
            case 8:
                str = "tuv";
                break;
            case 9:
                str = "wxyz";
                break;
            default:
                break;
        }
        return str;
    }
    vector<string> letterCombinations(string digits) {
        if(0==digits.size()){
            vector<string> ans;
            return ans;
        }
        vector<string> ans;
        vector<string> temp;
        string digit_str = digitToString(digits[0]-'0');
        string remain = digits.substr(1);
        temp = letterCombinations(remain);
        if(0==temp.size())
            temp.push_back("");
        for(char ch : digit_str){
            for(string s : temp){
                ans.push_back(ch+s);
            }
        }
        return ans;
    }
};