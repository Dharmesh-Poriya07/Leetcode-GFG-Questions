class Solution {
public:
    void banNearestOpponent(string &senate,char opponent,int starting,vector<bool> &banned){
        while(true){
            if(!banned[starting] and senate[starting] == opponent){
                banned[starting] = true;
                break;
            }
            starting ++;
            starting %= senate.size();
        }
    }
    string predictPartyVictory(string senate) {
        int n = senate.size();
        vector<bool> banned(n,false);
        int r_count = 0, d_count = 0;
        for(char ch : senate){
            if('R' == ch) r_count ++;
            else d_count ++;
        }
        
        int i = 0;
        while(0<r_count and 0<d_count){
            if(!banned[i]){
                if('R'==senate[i]){
                    banNearestOpponent(senate,'D',(i+1)%n,banned);
                    d_count --;
                }else{
                    banNearestOpponent(senate,'R',(i+1)%n,banned);
                    r_count --;
                }
            }
            i ++;
            i %= n;
        }
        
        return r_count == 0? "Dire" : "Radiant";
    }
};