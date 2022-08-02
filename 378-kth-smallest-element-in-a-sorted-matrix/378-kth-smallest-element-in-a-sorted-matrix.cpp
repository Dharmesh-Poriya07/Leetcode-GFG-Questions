class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        map<int,int> freq;
        for(auto m : matrix)
            for(int ele : m)
                freq[ele]++;
        int temp = 0;
        int ans = -1;
        for(auto it : freq){
            temp += it.second;
            if(temp>=k){
                ans = it.first;
                break;
            }
        }
        return ans;
    }
};