class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long low = 1, high = maxSum;
        int ele_right = n-index-1;
        int ele_left = index;

        int ans = INT_MIN;

        while(low<=high){
            long mid = (low+high) >> 1;

            long nth = mid-1;
            long nthsum_right, nthsum_left;
            nthsum_right = nthsum_left = (nth*(nth+1)) >> 1;
            long an_right = nth-ele_right;
            long an_left = nth-ele_left;

            if(an_right>0){
                nthsum_right -= ((an_right*(an_right+1)) >> 1);
            }else if(an_right < 0){
                an_right = abs(an_right);
                nthsum_right += an_right;
            }

            if(an_left>0){
                nthsum_left -= ((an_left*(an_left+1)) >> 1);
            }else if(an_left < 0){
                an_left = abs(an_left);
                nthsum_left += an_left;
            }

            if(mid+nthsum_right+nthsum_left<=maxSum){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};