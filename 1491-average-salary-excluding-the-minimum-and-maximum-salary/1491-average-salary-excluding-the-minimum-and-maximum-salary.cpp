class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        sort(begin(salary),end(salary));
        double sum = accumulate(salary.begin(),salary.end(),0);
        sum -= salary.front();
        sum -= salary.back();
        return sum/(n-2);
    }
};