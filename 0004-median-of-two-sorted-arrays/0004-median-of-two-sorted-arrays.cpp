class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        double _median = 0;
        int i=n-1,j=0;
        while(i>=0 && j<m){
            if(nums1[i] > nums2[j]){
                swap(nums1[i],nums2[j]);
                i--;
                j++;
            }else{
                break;
            }
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        if(n == m){
            int term1 = nums1[n-1];
            int term2 = nums2[0];
            _median = (term1 + term2)/2.0;
        }else if((n+m)%2 == 0){
            int term1;
            int term2;
            if(n>m){
                term1 = nums1[(m+n)/2];
                term2 = nums1[(m+n)/2 - 1];
            }else{
                term1 = nums2[(m+n)/2 - n];
                term2 = nums2[(m+n)/2 - n -1];
            }
            _median = (term1 + term2)/2.0;
        }else{
            if(n>m){
                _median = nums1[(n+m)/2];
            }else{
                _median = nums2[(m+n)/2 - n];
            }
        }
        return _median;
    }
};