class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        vector<pair<int,int>> cp; // capital and profits
        for(int i=0;i<profits.size();i++){
            cp.push_back({capital[i],profits[i]});
        }
        sort(cp.begin(),cp.end());
        int i=0;
        while(k--){
            while(i<cp.size() and w>=cp[i].first){
                pq.push(cp[i].second);
                i++;
            }
            if(!pq.empty()){
                w += pq.top();
                pq.pop();
            }
        }
        return w;
    }
};