class Solution {
public:
    long long getCost(vector<int>& nums, vector<int>& cost,long mid){
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += cost[i]*abs(nums[i]-mid);
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        // solution using convex function
        int low = nums.front();
        int high = nums.back();
        for(auto &n : nums){
            low = min(low,n);
            high = max(high,n);
        }
        long long ans = INT_MAX;
        while(low < high){
            long mid = low + ((high-low)>>2);
            long long cost1 = getCost(nums,cost,mid);
            long long cost2 = getCost(nums,cost,mid+1);
            ans = min(cost1,cost2);
            if(cost1>cost2){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};