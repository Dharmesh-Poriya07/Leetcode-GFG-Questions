class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int sz = nums.size();
        while(nums.size()>0 and nums.back()==0) nums.pop_back();
        reverse(begin(nums),end(nums));
        while(nums.size()>0 and nums.back()==0) nums.pop_back();
        int len = 0;
        int i=0,j=0,pos;
        bool flag=false;
        while(j<nums.size()){
            while(nums.size()>j){
                if(nums[j]==1) j++;
                else{
                    if(!flag) {
                        flag = true;
                        pos = j;
                        j++;
                    }else{
                        break;
                    }
                }
            }
            len = max(len,j-i-flag);
            i = pos+1;
            pos = j;
            j++;
        }
        if(sz!=nums.size() and len==nums.size()) return len;
        if(nums.size()>0 and len==nums.size()) len--;
        return len;
    }
};