class Solution {
private:
    void merge(vector<int> &nums,int left,int mid,int right){
        vector<int> left_arr(mid-left+1),right_arr(right-mid);
        vector<int> arr(right-left+1);
        for(int i=left,j=0;i<=mid;i++,j++) left_arr[j] = nums[i];
        for(int i=mid+1,j=0;i<=right;i++,j++) right_arr[j] = nums[i];
        
        int i,j,k;
        i = j = k = 0;
        while(i<left_arr.size() && j<right_arr.size()){
            if(left_arr[i]<=right_arr[j]){
                arr[k] = left_arr[i];
                i++;
            }else{
                arr[k] = right_arr[j];
                j++;
            }
            k++;
        }
        while(i<left_arr.size()) arr[k++] = left_arr[i++];
        while(j<right_arr.size()) arr[k++] = right_arr[j++];
        
        k=0;
        while(k<arr.size()) nums[left++] = arr[k++];
    }
    void mergeSort(vector<int> &nums,int left,int right){
        if(left<right){
            int mid = left+(right-left)/2;
            mergeSort(nums,left,mid);
            mergeSort(nums,mid+1,right);
            merge(nums,left,mid,right);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        for(int i=0,j=277;i<=2*1e4;i++,j++){
            cout<<j<<",";
        }
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};