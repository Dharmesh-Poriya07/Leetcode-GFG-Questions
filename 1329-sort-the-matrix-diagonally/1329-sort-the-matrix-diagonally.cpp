class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        //upperdiagonal
        for(int gap=0;gap<m;gap++){
            vector<int> nums;
            for(int i=0,j=gap;i<n && j<m;i++,j++)
                nums.push_back(mat[i][j]);
            
            sort(nums.begin(),nums.end());
            
            for(int i=0,j=gap,k=0;i<n && j<m;i++,j++){
                mat[i][j] = nums[k++];
            }
        }
        //lower diagonal
        for(int gap=0;gap<n-1;gap++){
            vector<int> nums;
            for(int i=1+gap,j=0;i<n && j<m;i++,j++)
                nums.push_back(mat[i][j]);
            
            sort(nums.begin(),nums.end());
            for(int i=1+gap,j=0,k=0;i<n && j<m;i++,j++)
                mat[i][j] = nums[k++];
            
        }
        return mat;
    }
};