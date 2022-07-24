class Solution {
private:
    bool binarySearch(int row,vector<vector<int>>& matrix,int &target){
        int low = 0;
        int high = matrix[row].size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[row][mid]==target){
                return true;
            }else if(matrix[row][mid]<target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;matrix.size()>i;i++){
            if(binarySearch(i,matrix,target)){
                return true;
            }
        }
        return false;
    }
};