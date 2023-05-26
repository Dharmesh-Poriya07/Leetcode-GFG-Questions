class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prev_greatest(n,0);
        prev_greatest[0] = height[0];
        int ans = 0, mx = height[n-1];
        for(int i=1;i<n;i++){
            prev_greatest[i] = max(prev_greatest[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            mx = max(mx,height[i]);
            ans += (abs(height[i]-min(mx,prev_greatest[i])));
        }
        return ans;
    }
};