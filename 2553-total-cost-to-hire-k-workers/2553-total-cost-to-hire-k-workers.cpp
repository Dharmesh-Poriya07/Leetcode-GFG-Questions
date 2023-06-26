class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        if(n==1) return costs.back();

        priority_queue<int,vector<int>,greater<int>> leftq,rightq;
        int left_ind = 0, right_ind = n-1;
        long long total_cost = 0;

        while(left_ind<n and right_ind>=0 and left_ind<=right_ind and left_ind<candidates){
            leftq.push(costs[left_ind++]);
            if(left_ind < right_ind)rightq.push(costs[right_ind--]);
        } 

        while(k--){
            int left_min = leftq.empty() ? INT_MAX : leftq.top();
            int right_min = rightq.empty() ? INT_MAX : rightq.top();

            if(left_min<=right_min){
                total_cost += left_min;
                leftq.pop();
                if(left_ind<=right_ind) leftq.push(costs[left_ind++]);
            }else{
                total_cost += right_min;
                rightq.pop();
                if(left_ind<=right_ind) rightq.push(costs[right_ind--]);
            }
        }
        return total_cost;
    }
};