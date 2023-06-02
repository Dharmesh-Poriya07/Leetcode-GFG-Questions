class Solution {
public:
    int bfs(vector<vector<int>>& bombs,int ind){
        int n = bombs.size();
        vector<int> vis(n,false);

        queue<int> q;
        q.push(ind);
        vis[ind] = true;
        int cnt = 0;
        while(!q.empty()){
            int curr = q.front(); q.pop();
            auto c1 = bombs[curr];
            int x1 = c1[0], y1 = c1[1];
            long r1 = c1[2];
            
            cnt ++;
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    int x2 = bombs[i][0], y2 = bombs[i][1];
                    long r2 = bombs[i][2];
                    long c1c2 = pow(x1-x2,2) + pow(y1-y2,2);
                    if(c1c2<=r1*r1){
                        q.push(i);
                        vis[i] = true;
                    }
                }
            }
        }
        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans = 0;
        for(int i=0;i<bombs.size();i++){
            ans = max(ans,bfs(bombs,i));
        }
        return ans;
    }
};