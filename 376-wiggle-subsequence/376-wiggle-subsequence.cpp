class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans = 1;
        bool positive,negative;
        positive = negative = true;
        for(int i=1;nums.size()>i;i++){
            int diff = nums[i]-nums[i-1];
            if(1==i){
                if(0>diff){
                    positive = true;
                    negative = false;
                    ans ++;
                }else if(0<diff){
                    negative = true;
                    positive = false;
                    ans ++;
                }
                continue;
            }
            if(positive && 0<diff){
                negative = true;
                positive = false;
                ans ++;
            }
            if(negative && 0>diff){
                negative = false;
                positive = true;
                ans ++;
            }
        }
        return ans;
    }
};