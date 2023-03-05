class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1)
            return 0;

        unordered_map<int, vector<int>>allIdx;

        for (int i = 0; i < arr.size(); i++) {
            allIdx[arr[i]].push_back(i);
        }

        vector<bool>vis(n, false);
        queue<int>q;
        int steps = 0;

        q.push(0);
        vis[0] = true;

        while(!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int currIdx = q.front(); q.pop();

                if (currIdx == n-1)
                    return steps;

                if (currIdx+1 < n && !vis[currIdx + 1]) {
                    q.push(currIdx+1);
                    vis[currIdx+1] = true;
                }
                if (currIdx-1 >= 0 && !vis[currIdx - 1]) {
                    q.push(currIdx-1);
                    vis[currIdx-1] = true;
                }
                for (auto nextIdx : allIdx[arr[currIdx]]) {
                    if (!vis[nextIdx]) {
                        q.push(nextIdx);
                        vis[nextIdx] = true;
                    }
                }
                allIdx[arr[currIdx]].clear();
            }

            steps++;
        }
        return -1;
    }
};