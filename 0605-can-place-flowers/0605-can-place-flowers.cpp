class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if(1==m){
            if(2>n and flowerbed[0]==0) return true;
            return flowerbed[0]==1 and 0==n ? true:false;
        }
        for(int i=0;i<m;i++){
            if(flowerbed[i])
                continue;
            if(0==i and i+1<m and 0==flowerbed[i+1]){
                flowerbed[i] = 1;
                n--;
            }else if(m-1==i and i-1>=0 and 0==flowerbed[i-1]){
                flowerbed[i] = 1;
                n--;
            }else if(0<i and i<m-1 and 0==flowerbed[i-1] and 0==flowerbed[i+1]){
                flowerbed[i] = 1;
                n--;
            }
        }
        return 0>=n;
    }
};