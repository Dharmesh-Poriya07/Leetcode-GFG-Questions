class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> temp;
        temp.push_back(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]>temp.back()){
                temp.push_back(a[i]);
            }else{
                int ind = lower_bound(temp.begin(),temp.end(),a[i])- temp.begin();
                temp[ind] = a[i];
            }
        }
        return temp.size();
    }
};