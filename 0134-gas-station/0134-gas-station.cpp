class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = accumulate(gas.begin(),gas.end(),0);
        int total_cost = accumulate(cost.begin(),cost.end(),0);
        if(total_cost>total_gas) return -1;
        int start_ind = 0;
        int current = 0;
        for(int i=0;i<cost.size();i++){
            current += (gas[i]-cost[i]);
            if(current < 0){
                start_ind = i+1;
                current = 0;
            }
        }
        return start_ind;
    }
};