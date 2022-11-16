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
            int mid = low + (high-low)/2;
            int result = guess(mid);
            if(0==result){
                ans = mid;
                break;
            }else if(-1==result){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};