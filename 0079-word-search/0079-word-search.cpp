class Solution {
private:
    vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    bool dfs(vector<vector<char>>& board, string &word,int r,int c,int ind){
        if(ind == word.size()) return true;
        
        if(0>r or 0>c or board.size()==r or board[0].size()==c or '.'==board[r][c] or board[r][c]!=word[ind]) return false;
        char ch = board[r][c];
        board[r][c] = '.';
        for(int i=0;i<4;i++){
            if(dfs(board,word,r+dir[i][0],c+dir[i][1],ind+1)){
                board[r][c] = ch;
                return true;
            }
        }   
        board[r][c] = ch;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j] and dfs(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};