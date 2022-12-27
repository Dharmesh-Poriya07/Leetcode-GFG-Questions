class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> diff;
        for(int i=0;i<capacity.size();i++) diff.push_back(capacity[i]-rocks[i]);
        
        sort(diff.begin(),diff.end());
        int mx_bag_with_full_cap = 0;
        for(int d : diff){
            if(d<=additionalRocks) additionalRocks -= d;
            else break;
            mx_bag_with_full_cap ++;
        }
        return mx_bag_with_full_cap;
    }
};