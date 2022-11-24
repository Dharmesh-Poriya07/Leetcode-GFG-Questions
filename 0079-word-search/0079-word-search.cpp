class Solution {
private:
    bool dfs(vector<vector<char>>& board, string word,int r,int c,int ind){
        if(ind == word.size()) return true;
        
        if(-1==r or -1==c or board.size()==r or board[0].size()==c or '.'==board[r][c] or (board[r][c] != word[ind])) return false;
        char temp = board[r][c];
        board[r][c] = '.';
        bool top = dfs(board,word,r-1,c,ind+1);
        bool right = dfs(board,word,r,c+1,ind+1);
        bool bottom = dfs(board,word,r+1,c,ind+1);
        bool left = dfs(board,word,r,c-1,ind+1);
        board[r][c] = temp;
        return (top or right or bottom or left);
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};