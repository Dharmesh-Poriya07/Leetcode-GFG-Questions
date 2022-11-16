/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        int ans;
        
        while(true){
            int r = rand();
            int guessNum = (r%(high-low+1))+low;
            int result = guess(guessNum);
            if(0==result){
                ans = guessNum;
                break;
            }else if(-1==result){
                high = guessNum-1;
            }else{
                low = guessNum+1;
            }
        }
        return ans;
    }
};