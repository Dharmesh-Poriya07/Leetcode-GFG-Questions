class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> graph(n);
        for(auto &f : flights){
            graph[f[0]].push_back({f[1],f[2]});
        }
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({0,src,0});
        vector<int> noOfStops(n,INT_MAX);
        while(!pq.empty()){
            auto [cost,node,stops] = pq.top();
            pq.pop();
            
            if(noOfStops[node] < stops) continue;
            noOfStops[node] = stops;
            if(node==dst) return cost;
            
            if(stops>k) continue;
            
            for(auto adj : graph[node]){
                pq.push({cost+adj[1],adj[0],stops+1});
            }
        }
        return -1;
    }
};