class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> pair;
        for(int i=1;i<n;i++){
            pair.push_back(weights[i]+weights[i-1]);
        }
        sort(pair.begin(),pair.end());
        long long mn=0,mx=0;
        for(int i=0;i<k-1;i++){
            mn += pair[i];
            mx += pair[n-i-2];
        }
        return mx-mn;
    }
};