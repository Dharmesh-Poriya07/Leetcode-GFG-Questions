class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26,0);
        priority_queue<pair<int,char>> pq;
        for(auto ch : s) count[ch-'a']++;

        for(int i=0;i<26;i++) if(count[i]) pq.push({count[i],'a'+i});
        string ans = "";

        if(pq.size()==1 and pq.top().first>1) return ans;

        while(pq.size()>1){
            auto t1 = pq.top(); pq.pop();
            auto t2 = pq.top(); pq.pop();
            ans.push_back(t1.second);
            ans.push_back(t2.second);
            t1.first = t1.first-1;
            t2.first = t2.first-1;
            if(t1.first>0) pq.push(t1);
            if(t2.first>0) pq.push(t2);
        }
        if(pq.size()==1){
            if(pq.top().first>1) return "";
            else ans.push_back(pq.top().second);
        }
        return ans;
    }
};