class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int low,high=0,ans;
        low = nums[0];
        for(int num : nums){
            high = max(high,num);
        }
        ans = high;
        
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isValid(nums,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        return ans;
    }
    
    bool isValid(vector<int> &nums,int x){
        long presum = 0,i=1;
        for(int num : nums){
            presum += num;
            if(presum>i*x) return false;
            i++;
        }
        return true;
    }
};