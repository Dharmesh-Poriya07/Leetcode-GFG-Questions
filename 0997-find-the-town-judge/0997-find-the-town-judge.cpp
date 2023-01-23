class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1,0),outdegree(n+1,0);
        for(auto &t : trust){
            indegree[t[1]]++;
            outdegree[t[0]]++;
        }
        for(int i=1;i<n+1;i++){
            if(n-1==indegree[i] and 0==outdegree[i]){
                return i;
            }
        }
        return -1;
    }
};