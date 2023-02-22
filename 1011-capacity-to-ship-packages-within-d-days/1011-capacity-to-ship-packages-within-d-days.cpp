class Solution {
    private:
    bool canShip(vector<int> &weights,int cap,int days){
        int d = 1,curr_w = 0;
        for(auto w : weights){
            if(w+curr_w<=cap){
                curr_w += w;
            }else{
                d++;
                curr_w = w;
            }
        }
        return d<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN;
        int high = 0;
        for(auto w : weights){
            low = max(low,w);
            high += w;
        }
        int ans;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(canShip(weights,mid,days)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};