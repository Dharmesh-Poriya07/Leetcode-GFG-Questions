class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> f(26,0);
        for(int t : tasks) f[t-'A']++;
        int mxf = *max_element(begin(f),end(f));
        int chunks = mxf-1;
        int idle = chunks*n;

        sort(rbegin(f),rend(f));
        for(int i=1;i<26;i++){
            idle -= min(f[i],chunks);
        }
        if(idle<0) return tasks.size();
        return idle+tasks.size();
    }
};