class Solution {
public:
    bool isValidSerialization(string s) {
        if(',' == s[0]) return false;
        if('#'==s[0]) {
            if(1==s.size()) return true;
            return false;
        }
        stack<string> st;
        s.push_back(',');
        string temp = "";
        for(int i=0;i<s.size();i++){
            if(','==s[i]){
                st.push(temp);
                while(2<st.size()){
                    string s1 = st.top();
                    st.pop();
                    string s2 = st.top();
                    st.pop();
                    string s3 = st.top();
                    st.pop();
                    if("#"==s1 and "#"==s2 and "#"==s3) return false;
                    if("#"==s1 and "#"==s2 and "#"!=s3) st.push("#");
                    else{
                        st.push(s3);
                        st.push(s2);
                        st.push(s1);
                        break;
                    }
                }
                temp.clear();
            }else{
                temp.push_back(s[i]);
            }
        }
        return 1==st.size() and "#"==st.top();
    }
};