class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left,right,leftmax,rightmax,ans;
        ans = left = leftmax = rightmax = 0;
        right = n-1;

        while(left<=right){
            if(height[left] <= height[right]){
                if(leftmax <= height[left]) leftmax = height[left];
                else ans += leftmax-height[left];
                left ++;
            }else{
                if(rightmax <= height[right]) rightmax = height[right];
                else ans += rightmax-height[right];
                right --;
            }
        }

        return ans;
    }
};