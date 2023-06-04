class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1, num = nums.front();
        for(int i=1;i<nums.size();i++){
            if(num == nums[i]){
                cnt ++;
            }else{
                if(cnt==0){
                    cnt = 1;
                    num = nums[i];
                }else
                    cnt --;
            }
        }
        return num;
    }
};