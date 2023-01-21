class Solution {
private:
    vector<string> ans;
    bool isIPValid(string ip){
        string num = "";
        int count = 0;
        for(int i=0;i<ip.size();i++){
            num = "";
            while(i<ip.size() and '.'!=ip[i]){
                num.push_back(ip[i]);
                i++;
            }
            count++;
            if(3<num.size()) return false;
            if(1<num.size() and '0'==num[0]) return false;
            if(255<stoi(num)) return false;
        }
        if(4>count) return false;
        return true;
    }
    void helper(string s,int dots,string temp){
        if(dots==0){
            if(3<s.size()) return;
            temp += s;
            if(isIPValid(temp)){
                ans.push_back(temp);
            }
            return;
        }
        for(int i=0;i<s.size() and i<3;i++){
            temp += s.substr(0,i+1);
            temp.push_back('.');
            helper(s.substr(i+1),dots-1,temp);
            temp.pop_back();
            int j=i+1;
            while(j--){
                temp.pop_back();
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        ans = vector<string>();
        if(12<s.size() or 4>s.size()) return {};
        string temp = "";
        helper(s,3,temp);
        return ans;
    }
};