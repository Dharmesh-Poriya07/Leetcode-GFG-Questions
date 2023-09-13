class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> left(ratings.size(),1);
        vector<int> right(ratings.size(),1);
        int ans=0;
        for(int i=0;ratings.size()>i;i++){
            if(0==i) continue;
            if(ratings[i]>ratings[i-1]){
                left[i] = left[i-1]+1;
            }
        }
        for(int i=ratings.size()-1;0<=i;i--){
            if(ratings.size()-1!=i){
                if(ratings[i]>ratings[i+1]){
                    right[i] = right[i+1]+1;
                }
            }
            
            ans += max(left[i],right[i]);
        }
        return ans;
    }
};