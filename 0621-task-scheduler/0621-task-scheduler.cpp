class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char t : tasks) freq[t-'A']++;

        priority_queue<int> pq;
        for(auto f : freq) if(f) pq.push(f);
        int ans = 0;
        while(!pq.empty()){
            vector<int> temp;
            int time = 0;
            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                    time++;
                } 
            }
            for(auto f : temp) if(f) pq.push(f);
            ans += pq.empty() ? time : n+1;
        }
        return ans;
    }
};