class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans = 0;
        for(int num : s){
            if(!s.count(num-1)){
                int currentN = num;
                int currentAns = 1;
                while(s.count(currentN+1)){
                    currentN += 1;
                    currentAns += 1;
                }
                ans = max(ans,currentAns);
            }
        }
        return ans;
    }
};