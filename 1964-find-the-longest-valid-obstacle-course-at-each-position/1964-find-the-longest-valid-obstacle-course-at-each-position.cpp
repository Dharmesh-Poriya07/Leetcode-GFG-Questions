class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& ob) {
        int n = ob.size();
        vector<int> ans(n, 1), lis;

        for (int i = 0; i < n; i++) {
            int index_to_start_lis = upper_bound(lis.begin(), lis.end(), ob[i]) - lis.begin();
            if (index_to_start_lis == lis.size()) {
                lis.push_back(ob[i]);
            }
            else {
                lis[index_to_start_lis] = ob[i];
            }
            ans[i] = index_to_start_lis+1;
        }
        return ans;
    }
};