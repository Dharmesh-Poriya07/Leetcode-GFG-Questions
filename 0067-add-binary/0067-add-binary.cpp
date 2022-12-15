class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string ans = "";
        while(0!=a.size() or 0!=b.size()){
            int sum = carry;
            if(0!=a.size()){
                sum += (a.back()-'0');
                a.pop_back();
            }
            if(0!=b.size()){
                sum += (b.back()-'0');
                b.pop_back();
            }
            ans.push_back((sum&1)+'0');
            sum >>= 1;
            carry = (sum);
        }
        if(carry) ans.push_back(carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};