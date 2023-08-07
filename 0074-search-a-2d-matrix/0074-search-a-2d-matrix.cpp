class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size(), m=mat[0].size();
        int left = 0, right = n-1;
        while(left<=right){
            int mid = (left+right)>>1;
            if(mat[mid][m-1]==target) return true;
            if(mat[mid][m-1]>target){
                if(mat[mid][0]<=target){
                    return binary_search(mat[mid].begin(),mat[mid].end(),target);
                }else{
                    right = mid-1;
                }
            }else{
                left = mid+1;
            }
        }
        return false;
    }
};