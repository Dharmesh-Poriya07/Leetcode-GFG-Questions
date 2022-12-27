class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for(int i=0;i<capacity.size();i++) capacity[i] -= rocks[i];
        
        sort(capacity.begin(),capacity.end());
        int mx_bag_with_full_cap = 0;
        for(int &cap : capacity){
            if(cap<=additionalRocks) additionalRocks -= cap;
            else break;
            mx_bag_with_full_cap ++;
        }
        return mx_bag_with_full_cap;
    }
};