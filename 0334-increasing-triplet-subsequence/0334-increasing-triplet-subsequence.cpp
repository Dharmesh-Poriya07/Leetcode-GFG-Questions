class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(3>nums.size()) return false;
        
        int left = INT_MAX;
        int middle = INT_MAX;
        
        for(int i : nums){
            if(i>middle) return true;
            
            if(i>left and i<middle) middle = i;
            else if(i<left) left = i;
        }
        return false;
    }
};