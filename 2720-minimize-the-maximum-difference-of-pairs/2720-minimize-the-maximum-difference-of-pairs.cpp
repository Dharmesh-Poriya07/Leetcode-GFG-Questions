class Solution {
private: 
    bool isPossible(vector<int> &nums,int p,int diff){
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<=diff){
                p--;
                i++;
            }
        }
        return 0>=p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        // element will make minimum difference with only adjacent element.
        
        int left = 0,ans,right;
        ans = right = nums.back()-nums.front();
        while(left<=right){
            int mid = left + (right-left)/2;
            if(isPossible(nums,p,mid)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};