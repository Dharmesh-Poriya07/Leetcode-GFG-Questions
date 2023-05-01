class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        // sort(begin(salary),end(salary));
        double sum = accumulate(salary.begin(),salary.end(),0);
        int mn = *min_element(salary.begin(),salary.end());
        int mx = *max_element(salary.begin(),salary.end());
        sum -= mn;
        sum -= mx;
        return sum/(n-2);
    }
};