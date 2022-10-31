class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
                
        for(int i=0;i<m;i++){
            int i1 = i,j1=0;
            while(i1<m and j1<n){
                if(matrix[i][0] != matrix[i1][j1])
                    return false;
                i1++;
                j1++;
            }
        }
        for(int j=1;j<n;j++){
            int i1 = 0,j1=j;
            while(i1<m and j1<n){
                if(matrix[0][j] != matrix[i1][j1])
                    return false;
                i1++;
                j1++;
            }
        }
        return true;
    }
};