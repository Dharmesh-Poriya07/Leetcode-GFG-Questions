class Solution:
    def mySqrt(self, x: int) -> int:
        ans = 0;
        low = 0;
        high = x;
        while low<=high :
            mid = low + (high-low)//2;
            sq = mid*mid;
            if(sq==x):
                ans = mid;
                break;
            elif(sq<x):
                ans = mid;
                low = mid+1;
            else:
                high = mid-1;
        return ans;
        