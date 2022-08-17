class Solution {
public:
    int myAtoi(string s) {
        // -2^31 = -2147483648
        // 2^31-1 = 2147483647
        
        long long int ans = 0;
        string digits = "";
        bool isNegative = false;
        int size = s.size();
        for(int i=0;i<size;i++){
            if(' '==s[i]){
                continue;
            }else if('-'==s[i]){
                if(size-1==i || size-1>i && '0'>s[i+1] && '9'<s[i+1]){
                    return 0;
                }else{
                    isNegative = true;
                    i++;
                    while(i<size && '0'<=s[i] && '9'>=s[i])
                        digits.push_back(s[i++]);
                    break;
                }
            }else if('+'==s[i]){
                if(size-1>i && '0'>s[i+1] && '9'<s[i+1]){
                    return 0;
                }else{
                    i++;
                    while(i<size && '0'<=s[i] && '9'>=s[i])
                        digits.push_back(s[i++]);
                    break;
                }
            }else if('0'<=s[i] && '9'>=s[i]){
                while(i<size && '0'<=s[i] && '9'>=s[i])
                    digits.push_back(s[i++]);
                break;
            }else{
                return 0;
            }
        }
        if(isNegative && '0'!=digits[0] && 11<digits.size())
            return INT_MIN;
        else if(!isNegative && '0'!=digits[0] && 10<digits.size())
            return INT_MAX;
        
        for(char d : digits){
            ans *= 10;
            ans += (d-'0');
        }
        if(isNegative){
            ans *= -1;
        }
        if((long long)INT_MAX<ans){
            return INT_MAX;
        }
        if((long long)INT_MIN>ans)
            return INT_MIN;
        return (int)ans;
    }
};