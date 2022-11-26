class Solution {
private:
    static bool myCmp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> timing;
        int n = startTime.size();
        for(int i=0;i<n;i++)
            timing.push_back({startTime[i],endTime[i],profit[i]});
        sort(timing.begin(),timing.end(),myCmp);
        
        vector<int> dp(n);
        dp[0] = timing[0][2];
        
        for(int i=1;i<n;i++){
            int include = timing[i][2];
            int last = -1;
            int low = 0;
            int high = i-1;
            while(low<=high){
                int mid = (low+high)/2;
                if(timing[mid][1]<=timing[i][0]){
                    last = mid;
                    low = mid+1;
                }else
                    high = mid-1;
            }
            if(last != -1) include += dp[last];
            int exclude = dp[i-1];
            dp[i] = max(include,exclude);
        }
        return dp[n-1];
    }
};