class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(int i=0;i<n;i++)
            tasks[i].push_back(i);
        sort(tasks.begin(),tasks.end());
        
        long long time = tasks[0][0];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int index = 0;
        vector<int> ans;
        while(index<n or !pq.empty()){
            while(index<n and tasks[index][0]<=time){
                pq.push({tasks[index][1],tasks[index][2]});
                index++;
            }
            auto current = pq.top();
            pq.pop();
            time += current.first;
            ans.push_back(current.second);
            if(pq.empty() and index<n and time<tasks[index][0]){
                time = tasks[index][0];
            }
        }
        return ans;
    }
};