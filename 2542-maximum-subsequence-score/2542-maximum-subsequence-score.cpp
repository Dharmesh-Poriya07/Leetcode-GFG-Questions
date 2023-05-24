class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> pairs;
        for(int i=0;i<nums1.size();i++) pairs.push_back({nums2[i],nums1[i]});
        
        sort(pairs.rbegin(),pairs.rend());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        long long curr_sum = 0;
        for(int i=0;i<k-1;i++){
            curr_sum += pairs[i].second;
            pq.push(pairs[i].second);
        }
        long long ans = 0;
        for(int i=k-1;i<nums1.size();i++){
            curr_sum += pairs[i].second;
            ans = max(ans,curr_sum*pairs[i].first);
            pq.push(pairs[i].second);
            curr_sum -= pq.top();
            pq.pop();
        }
        return ans;
    }
};