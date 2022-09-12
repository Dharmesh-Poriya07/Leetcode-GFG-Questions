class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score = 0;
        int low = 0, high = tokens.size()-1;
        if(0<tokens.size() and tokens[low]<=power){
            score ++;
            power -= tokens[low++];
        }else
            return score;
        
        while(low<=high){
            if(power>=tokens[low]){
                score ++;
                power -= tokens[low++];
            }else if(0<score and high>low and power+tokens[high]>tokens[low]){
                score --;
                power += tokens[high];
                high --;
            }else{
                break;
            }
        }
        return score;
    }
};