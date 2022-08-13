class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        low:int = 1;
        high:int = num;
        while low<=high:
            mid:int = low + (high-low)//2;
            sq:int = mid*mid;
            if sq==num:
                return True;
            elif sq<num:
                low = mid+1;
            else:
                high = mid-1;
            
        return False;