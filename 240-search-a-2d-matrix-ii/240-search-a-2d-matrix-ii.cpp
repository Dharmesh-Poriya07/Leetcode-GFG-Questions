class Solution {
private:
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size()-1;
        while(0<=col && matrix.size()>row){
            if(matrix[row][col]==target){
                return true;
            }else if(matrix[row][col]<target){
                row ++;
            }else{
                col --;
            }
        }
        return false;
    }
};