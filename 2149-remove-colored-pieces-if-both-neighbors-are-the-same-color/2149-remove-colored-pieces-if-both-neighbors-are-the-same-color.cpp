class Solution {
public:
    int countMoves(string &colors,char color){
        int moves = 0, n=colors.size();
        int i=0;
        while(i<n){
            int cnt = 0;
            while(i<n and colors[i]==color){
                cnt ++;
                i++;
            }
            i++;
            if(cnt>=3) moves += (cnt-2);
        }
        return moves;
    }
    bool winnerOfGame(string colors) {
        int alice_moves = countMoves(colors,'A');
        int bob_moves = countMoves(colors,'B');
        return alice_moves>bob_moves;
    }
};