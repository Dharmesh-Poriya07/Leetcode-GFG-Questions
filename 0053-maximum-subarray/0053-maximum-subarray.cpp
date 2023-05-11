class Solution {
public:
    void printSubarray(vector<int>& nums,int start,int end){
        while(start<=end){
            cout<<nums[start]<<" ";
            start++;
        }
        cout<<endl;
    }
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        int ansStart = -1,ansEnd = -1,start = -1;
        for(int i=0;i<nums.size();i++){
            if(0 == sum) start = i;
            sum += nums[i];
            if(sum > maxi){
                maxi = sum;  
                ansStart = start;
                ansEnd = i;
            } 
            if(sum < 0) sum = 0;
        }
        printSubarray(nums,ansStart,ansEnd);
        return maxi;
    }
};