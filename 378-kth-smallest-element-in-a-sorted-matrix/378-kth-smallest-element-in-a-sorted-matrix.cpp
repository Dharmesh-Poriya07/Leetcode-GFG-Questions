class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        map<int,int> freq;
        int temp_count = 0;
        int ans = -1;
        for(auto row : matrix){
            for(auto col : row){
                freq[col]++;
            }
        }
        for(auto it : freq){
            temp_count += it.second;
            if(temp_count >= k){
                ans = it.first;
                break;
            }
        }
        return ans;
    }
};