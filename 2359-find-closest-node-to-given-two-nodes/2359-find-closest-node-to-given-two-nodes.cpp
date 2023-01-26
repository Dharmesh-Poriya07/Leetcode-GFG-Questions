class Solution {
private:
    vector<int> findDistance(vector<vector<int>> &graph,int src){
        vector<int> dist(graph.size(),INT_MAX);
        queue<pair<int,int>> q;
        q.push({src,0});
        dist[src] = 0;
        vector<int> vis(graph.size(),false);
        while(!q.empty()){
            auto curr = q.front();q.pop();
            vis[curr.first] = true;
            for(int child : graph[curr.first]){
                if(!vis[child]){
                    dist[child] = curr.second+1;
                    q.push({child,dist[child]});
                }else{
                    // this else condition not required for given question,
                    // if we have nodes with more than one edge than this condition is required for finding smallest dstance.
                    dist[child] = min(dist[child],curr.second+1);
                }
            }
        }
        return dist;
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            if(-1!=edges[i]){
                graph[i].push_back(edges[i]);
            }
        }
        auto dist1 = findDistance(graph,node1);
        auto dist2 = findDistance(graph,node2);
        int mndist = INT_MAX;
        int node;
        for(int i=0;i<n;i++){
            int mxdist = max(dist1[i],dist2[i]);
            if(INT_MAX!=dist1[i] and INT_MAX!=dist2[i] and mndist>mxdist){
                mndist = mxdist;
                node = i;
            }
        }
        return mndist==INT_MAX?-1:node;
    }
};