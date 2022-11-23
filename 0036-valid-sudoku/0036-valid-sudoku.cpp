class Solution {
private:
    bool isValid(vector<vector<char>>& board){
        vector<unordered_map<char,int>> rows(9);
        vector<unordered_map<char,int>> columns(9);
        for(int i=0;i<9;i += 3){
            for(int j=0;j<9;j += 3){
                unordered_map<char,int> m;
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        if(0<m[board[x][y]] or 0<rows[x][board[x][y]] or 0<columns[y][board[x][y]]) return false;
                        if('0'<=board[x][y] and '9'>=board[x][y]){
                            m[board[x][y]] ++;
                            rows[x][board[x][y]]++;
                            columns[y][board[x][y]]++;
                        }
                        if(8==y and 0==rows[x].size()) return false;
                        if(8==x and 0==columns[y].size()) return false;
                    }
                }
                if(0==m.size()) return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return isValid(board);
    }
};