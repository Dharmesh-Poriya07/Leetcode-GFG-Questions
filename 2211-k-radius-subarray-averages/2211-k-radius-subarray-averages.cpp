class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> ps; // ps : prefix sum
        vector<int> res;
        ps.push_back(0);
        ps.push_back(nums.front());
        for(int i=1;i<n;i++) ps.push_back(ps.back()+nums[i]);
        
        for(int i=0;i<n;i++){
            if(i-k<0 or i+k>=n){
                res.push_back(-1);
                continue;
            }

            int avg = (ps[i+1+k]-ps[i-k])/(2*k+1);
            res.push_back(avg);
        }
        return res;
    }
};