class Solution {
private:
    int Floor(vector<int>& heaters,int x){
        int low = 0;
        int high = heaters.size()-1;
        int fl = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(x>=heaters[mid]){
                fl = heaters[mid];
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return fl;
    }
    int Ceil(vector<int>& heaters,int x){
        int low = 0;
        int high = heaters.size()-1;
        int cl = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(x<=heaters[mid]){
                cl = heaters[mid];
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return cl;
    }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        
        int radiuse = INT_MIN;
        for(int h=0;houses.size()>h;h++){
            int _floor = Floor(heaters,houses[h]);
            int _ceil = Ceil(heaters,houses[h]);
            int nearest;
            if(-1==_floor)
                nearest = abs(houses[h]-_ceil);
            else if(-1==_ceil)
                nearest = abs(houses[h]-_floor);
            else
                nearest = min(abs(houses[h]-_floor),abs(houses[h]-_ceil));
            radiuse = max(radiuse,nearest);
        }
        return radiuse;
    }
};