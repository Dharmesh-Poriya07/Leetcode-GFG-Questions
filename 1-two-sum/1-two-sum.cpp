class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> np;
        for(int i=0;i<nums.size();i++){
            np.push_back({nums[i],i});
        }
        sort(np.begin(),np.end());
        int low = 0, high = nums.size()-1;
        while(low<high){
            int sum = np[low].first+np[high].first;
            if(sum==target){
                return {np[low].second,np[high].second};
            }else if(sum<target){
                low ++;
            }else{
                high --;
            }
        }
        return {};
    }
};