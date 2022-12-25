class Solution {
private:
    int Floor(vector<int>& arr,int n,int target){
        int low=0, high=n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid] <= target)low = mid+1;
            else high = mid-1;
        }
        return high;
    }
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size(),m=queries.size();
        sort(nums.begin(),nums.end());
        vector<int> ans(m,0), psum(n);
        psum[0] = nums[0];
        for(int i=1;i<n;i++) psum[i] = psum[i-1]+nums[i];
        
        for(int i=0;i<m;i++) ans[i] = Floor(psum,n,queries[i])+1;
        
        return ans;
    }
};