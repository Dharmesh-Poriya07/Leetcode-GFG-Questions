class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k;i++){
            pq.push({abs(x-arr[i]),arr[i]});
        }
        
        for(int i=k;i<arr.size();i++){
            int diff = abs(x-arr[i]);
            if(pq.top().first>diff || (pq.top().first==diff && pq.top().second>arr[i])){
                pq.pop();
                pq.push({diff,arr[i]});
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};