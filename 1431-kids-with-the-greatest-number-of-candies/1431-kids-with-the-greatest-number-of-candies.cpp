class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mxele = *max_element(begin(candies),end(candies));
        
        vector<bool> ans;
        for(int c : candies){
            if(c+extraCandies>=mxele)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};