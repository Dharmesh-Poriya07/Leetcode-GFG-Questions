class Solution {
public:
    int mySqrt(int x) {
        int ans=0;
        int low = 1,high=x;
        while(low<=high){
            long long mid = low + (high-low)/2;
            long long int sq = mid*mid;
            if(sq==x){
                ans = mid;
                break;
            }else if(sq>x){
                high = mid-1;
            }else{
                ans = mid;
                low = mid+1;
            }
        }
        return ans;
    }
};