class Solution {
private:
    void merge(vector<int> &ans,vector<pair<int,int>> &vp,int left,int mid,int right){
        vector<pair<int,int>> temp(right-left+1);
        int i=left;
        int j=mid+1;
        int k=0;
        
        while(i<=mid && j<=right){
            if(vp[i].first<=vp[j].first){
                temp[k++] = vp[j++];
            }else{
                ans[vp[i].second] += right-j+1;
                temp[k++] = vp[i++];
            }
        }
        while(i<=mid){
            temp[k++] = vp[i++];
        }
        while(j<=right){
            temp[k++] = vp[j++];
        }
        for(int i=left;i<=right;i++){
            vp[i] = temp[i-left];
        }
    }
    void mergeSort(vector<int> &ans,vector<pair<int,int>> &vp,int left,int right){
        if(left<right){
            int mid = left + (right-left)/2;
            mergeSort(ans,vp,left,mid);
            mergeSort(ans,vp,mid+1,right);
            merge(ans,vp,left,mid,right);
        }
    }
public:
    vector<int> countSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,0);
	    vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++){
            vp[i] = {arr[i],i};
        }
        mergeSort(ans,vp,0,n-1);
        return ans;
    }
};