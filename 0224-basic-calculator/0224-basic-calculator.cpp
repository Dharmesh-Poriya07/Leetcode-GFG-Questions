class Solution {
public:
    int calculate(string s) {
        int sum = 0;
        stack<int> st;
        int sign = 1;
        
        for(int i=0;i<s.size();i++){
            if(' ' == s[i]) continue;
            if('0'<=s[i] and '9'>=s[i]){
                int num = 0;
                while(s.size()>i and '0'<=s[i] and '9'>=s[i]){
                    num *= 10;
                    num += (s[i]-'0');
                    i++;
                }
                sum += num*sign;
                i--;
            }else if('+' == s[i]){
                sign = 1;
            }else if('-' == s[i]){
                sign = -1;
            }else if('(' == s[i]){
                st.push(sum);
                st.push(sign);
                sum = 0;
                sign=1;
            }else {
                sum *= st.top();
                st.pop();
                sum += st.top();
                st.pop();
            }
        }
        return sum;
    }
};