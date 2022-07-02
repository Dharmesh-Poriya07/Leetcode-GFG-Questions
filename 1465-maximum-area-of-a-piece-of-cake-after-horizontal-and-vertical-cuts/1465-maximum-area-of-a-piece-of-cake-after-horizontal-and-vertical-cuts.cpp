class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mxwidth = INT_MIN;
        int mxheight = INT_MIN;
        long long int mod = 1000000007;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        mxwidth = max(abs(0-verticalCuts[0]),w-verticalCuts.back());
        for(int i=1;i<verticalCuts.size();i++){
            mxwidth = max(mxwidth,abs(verticalCuts[i]-verticalCuts[i-1]));
        }
        mxheight = max(abs(0-horizontalCuts[0]),h-horizontalCuts.back());
        for(int i=1;i<horizontalCuts.size();i++){
            mxheight = max(mxheight,abs(horizontalCuts[i]-horizontalCuts[i-1]));
        }
        long long int ans = ((mxheight%mod)*(mxwidth%mod))%mod;
        return ans;
    }
};