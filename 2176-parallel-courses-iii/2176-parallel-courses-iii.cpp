class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> indegree(n,0), adj[n], mx_time(n,0); // graph and indegree of relations and mx_time is for store maximum time required for completing chain of course (like : A(1)->B(2)->C(3))

        for(auto r : relations){
            indegree[r[1]-1]++; // counting indegree
            adj[r[0]-1].push_back(r[1]-1); // adding next course to prev course list
        } 
        queue<int> q; // queue for iterating
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                mx_time[i] = time[i];
                q.push(i); // adding all the courses which are not dependent on other
            } 
        } 

        int ans = 0;
        while(!q.empty()){
            auto curr = q.front(); q.pop();

            for(auto next : adj[curr]){
                indegree[next]--;
                if(0==indegree[next]){
                    q.push(next);
                }
                mx_time[next] = max(mx_time[next],mx_time[curr]+time[next]);
            }
        }

        for(int t : mx_time) ans = max(ans,t);
        return ans;
    }
};