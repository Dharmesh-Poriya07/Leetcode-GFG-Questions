class Solution {
private:
    vector<vector<string>> ans;
    void nQueen(int row,vector<string> &temp, vector<bool> &cols, vector<bool> &rightd, vector<bool> &leftd){
        int n = temp.size();
        if(row == n){
            ans.push_back(temp);
            return;
        } 

        for(int j=0;j<n;j++){
            if(!cols[j] and !rightd[row+j] and !leftd[n-1+row-j]){
                temp[row][j] = 'Q';

                cols[j] = rightd[row+j] = leftd[n-1+row-j] = true;
                nQueen(row+1,temp,cols,rightd,leftd);
                cols[j] = rightd[row+j] = leftd[n-1+row-j] = false;

                temp[row][j] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n,string(n,'.'));
        vector<bool> cols(n,false), rightd(2*n-1,false), leftd(2*n-1,false);
        nQueen(0,temp,cols,rightd,leftd);
        return ans;
    }
};