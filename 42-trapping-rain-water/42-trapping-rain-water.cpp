class Solution {
public:
    int trap(vector<int> &height) {
        int left=0; int right=height.size()-1;
        int ans=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxleft) maxleft=height[left];
                else ans+=maxleft-height[left];
                left++;
            }
            else{
                if(height[right]>=maxright) maxright= height[right];
                else ans+=maxright-height[right];
                right--;
            }
        }
        return ans;
    }
};