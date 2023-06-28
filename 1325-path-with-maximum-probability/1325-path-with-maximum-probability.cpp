class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> graph[n];
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        vector<double> dist(n,INT_MIN);
        dist[start] = 0;
        priority_queue<pair<double,int>> pq;
        pq.push({1,start});
        while(!pq.empty()){
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto v : graph[node]){
                if(dist[v.first]<prob*v.second){
                    dist[v.first] = prob*v.second;
                    pq.push({dist[v.first],v.first});
                }
            }
        }
        if(dist[end]==INT_MIN) return 0;
        return dist[end];
    }
};