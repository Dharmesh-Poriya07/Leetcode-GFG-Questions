class Solution {
private:
    int bsearch(vector<int> &num,int left,int right,int target){
        if(left>right) return -1;
        int mid = left+(right-left)/2;
        if(num[mid]==target){
            return mid;
        }else if(num[mid]<target){
            return bsearch(num,mid+1,right,target);
        }
        return bsearch(num,left,mid-1,target);
    }
public:
    int search(vector<int>& nums, int target) {
        return bsearch(nums,0,nums.size()-1,target);
    }
};