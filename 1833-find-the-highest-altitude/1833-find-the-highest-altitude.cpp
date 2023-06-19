class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest_gain = 0;
        int current_gain = 0;
        for(auto g : gain){
            current_gain += g;
            if(highest_gain<current_gain) highest_gain = current_gain;
        }
        return highest_gain;
    }
};