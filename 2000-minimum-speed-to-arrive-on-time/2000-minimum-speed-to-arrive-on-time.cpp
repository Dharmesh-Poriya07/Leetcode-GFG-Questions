class Solution {
public:
    bool isPossible(vector<int> &dist,double h,int speed){
        double curr = 0;
        for(auto d : dist){
            curr = ceil(curr);
            curr += ((1.0*d)/(1.0*speed));
        }
        // cout<<speed<<"=="<<curr<<endl;
        return curr <= h;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int low = 1, high = 1e7;
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossible(dist,hour,mid)){
                high = mid-1;
                ans = mid;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};