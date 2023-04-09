class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> g[n];
        vector<int> indegree(n,0);
        for(auto e : edges){
            g[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        
        queue<int> q;
        vector<vector<int>> dp(n,vector<int>(26,0));
        int visited = 0, ans = 0;
        
        for(int i=0;i<n;i++){
            if(0==indegree[i]){
                q.push(i);
                dp[i][colors[i]-'a'] = 1;
            }
        }
        
        while(!q.empty()){
            int u = q.front(); q.pop();
            visited++;
            int cmax = *max_element(begin(dp[u]),end(dp[u]));
            ans = max(ans,cmax);
            for(int v : g[u]){
                for(int color=0;color<26;color++){
                    dp[v][color] = max(dp[v][color],dp[u][color]+(color==colors[v]-'a'));
                }
                indegree[v]--;
                if(0==indegree[v])
                    q.push(v);
            }
        }
        // visited==n? there is no cycle : cycle present
        if(visited<n){
            return -1;
        }
        
        
        return ans;
    }
};