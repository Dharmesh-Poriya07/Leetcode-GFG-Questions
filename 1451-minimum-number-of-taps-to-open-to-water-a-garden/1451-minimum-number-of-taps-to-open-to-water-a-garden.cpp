class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int left,right,open,ind;
        left = right = open = ind = 0;
        while(right<n){
            for(int i=ind;i<ranges.size();i++){
                if(i-ranges[i]<=left and i+ranges[i]>right){
                    right = i+ranges[i];
                    ind = i;
                }
            }
            if(left==right) return -1;
            open++;
            left = right;
        }
        return open;
    }
};