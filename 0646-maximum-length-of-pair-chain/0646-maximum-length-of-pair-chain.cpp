class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });

        int ans = 1;
        for(int i=1, prev=0;i<pairs.size();i++){
            if(pairs[i][0]>pairs[prev][1]){
                ans ++;
                prev = i;
            }
        }
        return ans;
    }
};