class Solution {
    long long computeResult(long long op1,long long op2,char t){
        long long result;
        switch(t){
            case '+':
                result = op1+op2;
                break;
            case '-':
                result = op1-op2;
                break;
            case '*':
                result = op1*op2;
                break;
            case '/':
                result = op1/op2;
                break;
        }
        return result;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        for(string t : tokens){
            if(1==t.size() and ('+'==t[0] or '-'==t[0] or '*'==t[0] or '/'==t[0])){
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                long long result = computeResult(op1,op2,t[0]);
                s.push(result);
            }else{
                s.push(stoi(t));
            }
        }
        return s.top();
    }
};