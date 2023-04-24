class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int st : stones)
            pq.push(st);
        
        while(!pq.empty() and 1<pq.size()){
            int st1 = pq.top(); pq.pop();
            int st2 = pq.top(); pq.pop();
            
            if(st1 != st2){
                pq.push(st1-st2);
            }
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};