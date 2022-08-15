class Solution {
private:
    vector<int> bSearch(vector<int>& arr, int x){
        int low = 0;
        int high = arr.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]==x){
                return {mid-1,mid};
            }else if(x>arr[mid]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return {high,low};
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        if(x<=arr[0]){
            ans = vector<int>(arr.begin(),arr.begin()+k);
            return ans;
        }
        if(x>=arr.back()){
            ans = vector<int>(arr.end()-k,arr.end());
            return ans;
        }
        auto lh = bSearch(arr,x);
        int high = lh[1];
        int low = lh[0];
        while(0<k){
            if(high==arr.size()){
                while(k--)
                    ans.push_back(arr[low--]);
                break;
            }
            if(low==-1){
                while(k--)
                    ans.push_back(arr[high++]);
                break;
            }
            if(x-arr[low]<=arr[high]-x)
                ans.push_back(arr[low--]);
            else
                ans.push_back(arr[high++]);
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};