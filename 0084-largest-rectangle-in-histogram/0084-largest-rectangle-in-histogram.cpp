class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> ps(n),ns(n); // ps : previous_smallest, ns : next_smallest

        stack<int> st;
        // finding next smallest
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty()) ns[i] = n;
            else ns[i] = st.top();
            st.push(i);
        }                
        while(!st.empty()) st.pop();
        // finding previous smallest
        for(int i=0;i<n;i++){
            while(!st.empty() and heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty()) ps[i] = -1;
            else ps[i] = st.top();
            st.push(i);
        }

        int mxarea = 0;
        for(int i=0;i<n;i++){
            mxarea = max(mxarea,heights[i]*abs(ns[i]-ps[i]-1));
        }
        return mxarea;
    }
};