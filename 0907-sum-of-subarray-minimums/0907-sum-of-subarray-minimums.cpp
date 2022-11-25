class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<long long> left(n),right(n);
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++){
            int count = 1;
            while(!s.empty() and s.top().first>arr[i]){
                count += s.top().second;
                s.pop();
            }
            left[i] = count;
            s.push({arr[i],count});
        }
        while(!s.empty())
            s.pop();
        for(int i=n-1;i>=0;i--){
           int count = 1;
            while(!s.empty() and s.top().first>=arr[i]){
                count += s.top().second;
                s.pop();
            }
            right[i] = count;
            s.push({arr[i],count});
        }
        long long ans = 0;
        int mod = 1000000007;
        for(int i=0;i<n;i++){
            ans = (ans%mod + (left[i]*right[i]*arr[i])%mod)%mod;
        }
        return ans;
    }
};