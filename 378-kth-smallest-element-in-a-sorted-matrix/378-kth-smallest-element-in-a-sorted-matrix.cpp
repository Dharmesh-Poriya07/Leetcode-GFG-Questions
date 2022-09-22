class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> mxh;
        for(auto row : matrix){
            for(auto col : row){
                mxh.push(col);
                if(mxh.size()>k)
                    mxh.pop();
            }
        }
        return mxh.top();
    }
};