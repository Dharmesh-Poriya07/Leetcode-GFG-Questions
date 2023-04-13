class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size(), j=0;
        for(int i=0;i<n;i++){
            st.push(pushed[i]);
            while(!st.empty() and j<n and popped[j]==st.top()){
                st.pop();
                j++;
            }
        }
        return (st.empty() and j==n);
    }
};