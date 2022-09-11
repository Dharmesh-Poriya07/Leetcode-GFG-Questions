class Solution {
private:
    static bool myCmp(pair<int,int> &a,pair<int,int> &b){
        return a.first>b.first;
    }
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int mod = 1e9+7;
        vector<pair<int,int>> se;
        for(int i=0;i<n;i++)
            se.push_back({efficiency[i],speed[i]});
        sort(se.begin(),se.end(),myCmp);
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        long long sum = 0,ans = 0;
        for(int i=0;i<n;i++){
            sum += se[i].second;
            pq.push(se[i].second);
            if(pq.size()>k){
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans,sum*se[i].first);
        }
        return ans%mod;
    }
};