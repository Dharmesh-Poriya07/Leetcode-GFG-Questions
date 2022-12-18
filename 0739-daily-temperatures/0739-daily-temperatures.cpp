class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<pair<int,int>> s;
        for(int i=n-1;0<=i;i--){
            while(!s.empty() and s.top().first<=temperatures[i]) s.pop();
            ans[i] = (s.empty()?i:s.top().second)-i;
            s.push({temperatures[i],i});
        }
        return ans;
    }
};