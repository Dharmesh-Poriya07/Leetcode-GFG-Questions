class Solution {
private:
    bool isRowValid(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            unordered_map<char,int> m;
            for(int j=0;j<9;j++){
                if(0<m[board[i][j]]) return false;
                if('0'<=board[i][j] and '9'>=board[i][j]) m[board[i][j]] ++;
            }
            if(0==m.size()) return false;
        }
        return true;
    }
    bool isColumnValid(vector<vector<char>>& board){
        for(int j=0;j<9;j++){
            unordered_map<char,int> m;
            for(int i=0;i<9;i++){
                if(0<m[board[i][j]]) return false;
                if('0'<=board[i][j] and '9'>=board[i][j]) m[board[i][j]] ++;
            }
            if(0==m.size()) return false;
        }
        return true;
    }
    bool isSquareValid(vector<vector<char>>& board){
        for(int i=0;i<9;i += 3){
            for(int j=0;j<9;j += 3){
                unordered_map<char,int> m;
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        if(0<m[board[x][y]]) return false;
                        if('0'<=board[x][y] and '9'>=board[x][y]) m[board[x][y]] ++;
                    }
                }
                if(0==m.size()) return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool checkrow = isRowValid(board);
        bool checkcolumn = isColumnValid(board);
        bool checksq = isSquareValid(board);
        return (checkrow and checkcolumn and checksq);
    }
};