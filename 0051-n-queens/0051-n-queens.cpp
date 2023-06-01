class Solution {
private:
    vector<vector<string>> ans;
    bool isValid(vector<string> &temp,int r,int c){
        int n = temp.size();
        for(int i=r-1,j=c-1;i>=0 and j>=0;i--,j--){
            if('Q'==temp[i][j])
                return false;
        }
        for(int i=r-1,j=c+1;i>=0 and j<n;i--,j++){
            if('Q'==temp[i][j])
                return false;
        }
        for(int i=r-1;i>=0;i--){
            if('Q'==temp[i][c])
                return false;
        }
        return true;
    }
    void nQueen(int row,vector<string> &temp){
        if(row == temp.size()){
            ans.push_back(temp);
            return;
        } 

        for(int j=0;j<temp.size();j++){
            temp[row][j] = 'Q';
            if(isValid(temp,row,j)){
                nQueen(row+1,temp);
            }
            temp[row][j] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n,string(n,'.'));
        nQueen(0,temp);
        return ans;
    }
};