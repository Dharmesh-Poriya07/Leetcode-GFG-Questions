class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0;i<n;i++)
            if(-1 != manager[i])
                adj[manager[i]].push_back(i);
        

        queue<pair<int,int>> q;
        q.push({headID,informTime[headID]});
        int mxtime = 0;

        while(!q.empty()){
            auto curr = q.front(); q.pop();
            mxtime = max(mxtime,curr.second);
            for(auto v : adj[curr.first]){
                q.push({v,curr.second+informTime[v]});
            }
        }
        return mxtime;
    }
};