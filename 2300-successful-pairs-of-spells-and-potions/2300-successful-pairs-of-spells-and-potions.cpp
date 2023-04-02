class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs;
        sort(potions.begin(),potions.end());
        int m = potions.size();
        for(long long s : spells){
            int low = 0;
            int high = m-1;
            while(low<=high){
                int mid = low + (high-low)/2;
                long long product = s*potions[mid];
                if(product>=success){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            pairs.push_back(m-low);
        }
        return pairs;
    }
};