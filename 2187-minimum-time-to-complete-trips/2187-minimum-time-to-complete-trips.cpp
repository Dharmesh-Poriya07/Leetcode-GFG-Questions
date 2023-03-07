class Solution {
private:
    bool isPossible(vector<int>& time,long long avltime,int &totalTrips){
        long long currentTrips = 0;
        for(int i=0;i<time.size() and time[i]<=avltime;i++){
            currentTrips += (avltime/time[i]);
        }
        return currentTrips>=totalTrips;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
        long long left = time[0], right = ((long long)time[0])*totalTrips;
        long long ans;
        while(left<=right){
            long long mid = left + (right-left)/2;
            if(isPossible(time,mid,totalTrips)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};