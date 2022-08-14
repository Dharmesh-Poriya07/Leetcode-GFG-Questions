class Solution:
    def firstOccurance(self,nums:List[int],target:int)->List[int]:
        ans = -1;
        low = 0;
        high = len(nums)-1;
        while low<=high:
            mid = low + (high-low)//2;
            if(nums[mid]==target):
                if(0<mid and nums[mid-1]==target):
                    ans = mid-1;
                    high = mid-2;
                else:
                    ans = mid;
                    break;
            elif(nums[mid]>target) :
                high = mid-1;
            else:
                low = mid+1;
            
            
        return ans;
        
    def lastOccurance(self,nums:List[int],target:int)->List[int]:
        ans = -1;
        low = 0;
        high = len(nums)-1;
        while low<=high:
            mid = low + (high-low)//2;
            if(nums[mid]==target):
                if(len(nums)-1>mid and nums[mid+1]==target):
                    ans = mid+1;
                    high = mid+2;
                else:
                    ans = mid;
                    break;
                ans = mid;
                low = mid+1;
            elif(nums[mid]>target):
                high = mid-1;
            else:
                low = mid+1;
            
            
        return ans;
        
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        focuurance = self.firstOccurance(nums,target);
        loccurance = self.lastOccurance(nums,target);
        return [focuurance,loccurance];