class Solution {
public:
    int dp[101][201], mod;
    int solve(vector<int>& locations, int start, int finish, int fuel){
        if(fuel<=0) return start==finish?1:0;
        if(-1 != dp[start][fuel]) return dp[start][fuel];
        int routes = 0;
        if(start==finish) routes = 1;
        for(int i=0;i<locations.size();i++){
            int diff = abs(locations[i]-locations[start]);
            if(start != i and diff<=fuel){
                routes = (routes%mod + solve(locations,i,finish,fuel-diff)%mod)%mod;
            }
        }
        return dp[start][fuel] = routes;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp,-1,sizeof(dp));
        mod = 1e9+7;
        return solve(locations,start,finish,fuel);
    }
};