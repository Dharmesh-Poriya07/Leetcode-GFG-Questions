class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(),piles.end());
        while(k--){
            int current = pq.top();
            pq.pop();
            current -= (current/2);
            pq.push(current);
        }
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};