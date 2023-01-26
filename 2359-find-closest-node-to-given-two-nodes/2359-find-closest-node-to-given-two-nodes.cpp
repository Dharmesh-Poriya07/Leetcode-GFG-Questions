class Solution {
private:
    vector<int> findDistance(vector<int>& edges,int src){
        vector<int> dist(edges.size(),INT_MAX);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        while(!q.empty()){
            int parent = q.front();q.pop();
            int child = edges[parent];
            if(child!=-1 and dist[child]==INT_MAX){
                dist[child] = dist[parent]+1;
                q.push(child);
            }
            // else{
            //     // this else condition not required for given question,
            //     // if we have nodes with more than one edge than this condition is required for finding smallest dstance.
            //     dist[child] = min(dist[child],curr.second+1);
            // }
        }
        return dist;
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        auto dist1 = findDistance(edges,node1);
        auto dist2 = findDistance(edges,node2);
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