class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        
        for(auto it : mp){
            if(1<it.second.size()){
                for(int j=1;it.second.size()>j;j++)   {
                    if(abs(it.second[j]-it.second[j-1])<=k)
                        return true;
                }
            }
        }
        return false;
    }
};