class Solution {
private:
    bool isValid(vector<int>& piles, int k,int h){
        long long reqh = 0;
        for(int i=0;i<piles.size();i++){
            if(0==piles[i]%k) reqh += (piles[i]/k);
            else reqh += (piles[i]/k)+1;
        }
        return reqh<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k;
        int left = 1, right = 0;
        for(int i : piles) right = max(right,i);
        while(left<=right){
            int mid = left+(right-left)/2;
            if(isValid(piles,mid,h)){
                k = mid;
                right = mid-1;
            } 
            else left = mid+1;
        }
        return k;
    }
};