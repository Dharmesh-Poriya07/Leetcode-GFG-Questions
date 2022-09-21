class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0;
        vector<int> ans;
        for(int i=0;nums.size()>i;i++)
            if(0==nums[i]%2)
                evenSum += nums[i];
            
        
        for(auto q : queries){
            int csum = nums[q[1]]+q[0];
            if(0==nums[q[1]]%2){
                if(0==csum%2){
                    ans.push_back(evenSum+q[0]);
                }else{
                    ans.push_back(evenSum-nums[q[1]]);
                }
            }else{
                if(0==csum%2){
                    ans.push_back(evenSum+csum);
                }else{
                    ans.push_back(evenSum);
                }
            }
            nums[q[1]] = csum;
            evenSum = ans.back();
        }
        return ans;
            
    }
};