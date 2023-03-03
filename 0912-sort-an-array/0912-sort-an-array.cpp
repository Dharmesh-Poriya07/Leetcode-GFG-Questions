class Solution {
private:
    void mergeTwoSortedArray(vector<int> &nums,int left,int mid,int right){
        vector<int> left_arr,right_arr;
        
        for(int i=left;i<=mid;i++) left_arr.push_back(nums[i]);
        for(int i=mid+1;i<=right;i++) right_arr.push_back(nums[i]);
        
        int i,j,k;
        i = j = 0;
        k = left;
        
        while(i<left_arr.size() and j<right_arr.size()){
            if(left_arr[i]<=right_arr[j]) nums[k] = left_arr[i++];
            else nums[k] = right_arr[j++];
            k++;
        }
        
        while(i<left_arr.size()) nums[k++] = left_arr[i++];
        while(j<right_arr.size()) nums[k++] = right_arr[j++];
    }
    void mergeSort(vector<int> &nums,int left,int right){
        if(left<right){
            int mid = left+(right-left)/2;
            mergeSort(nums,left,mid);
            mergeSort(nums,mid+1,right);
            mergeTwoSortedArray(nums,left,mid,right);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};