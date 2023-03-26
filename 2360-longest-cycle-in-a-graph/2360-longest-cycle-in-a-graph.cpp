class Solution {
public:
    int answer = -1;

    void dfs(int src, vector<int> graph[], unordered_map<int, int>& cvt, vector<bool>& visit) {
        visit[src] = true;
        for (auto neighbor : graph[src]) {
            if (!visit[neighbor]) {
                cvt[neighbor] = cvt[src] + 1;
                dfs(neighbor, graph, cvt, visit);
            } 
            // if neighbor is exist in cvt then that means that neighbor is visited during current loop and it create cycle.
            else if (cvt.find(neighbor) != cvt.end()) {
                answer = max(answer, cvt[src] - cvt[neighbor] + 1);
            }
        }
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> graph[n];
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1)
                graph[i].push_back(edges[i]);
        }

        vector<bool> visit(n);
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                unordered_map<int, int> current_visit_time;
                current_visit_time[i] = 1;
                dfs(i, graph, current_visit_time, visit);
            }
        }
        return answer;
    }
};