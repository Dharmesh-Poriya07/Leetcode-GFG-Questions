class Solution {
private:
    int binarySearch(vector<int> &arr,int left,int right,int target){
        while(left<=right){
            int mid = left + (right-left)/2;
            if(arr[mid]==target) return mid;
            else if(arr[mid]<target) left = mid+1;
            else right = mid-1;
        }
        return -1;
    }
public:
    int findKthPositive(vector<int>& arr, int k) {
        int current_num = 1;
        while(k>0){
            if(-1==binarySearch(arr,0,arr.size()-1,current_num)){
                k--;
            }
            current_num++;
        }
        return current_num-1;
    }
};