class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();

        for(int i=0;i<n;i++){
            string temp = "";
            for(auto c : to_string(nums[i])) temp.push_back(c);
            int j=i;
            while(j+1<n and nums[j]+1==nums[j+1]){
                j++;
            }
            if(j!=i){
                temp.push_back('-'); temp.push_back('>');
                for(auto c : to_string(nums[j])) temp.push_back(c);
            }
            ans.push_back(temp);
            i=j;
        }
        return ans;
    }
};