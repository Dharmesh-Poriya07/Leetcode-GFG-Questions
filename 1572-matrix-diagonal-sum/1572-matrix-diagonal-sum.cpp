class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m = mat.size();
        int sum = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j) sum += mat[i][j];
                if(j==m-i-1) sum += mat[i][j];
            }
        }
        if(m%2) sum -= mat[m/2][m/2];
        return sum;
    }
};