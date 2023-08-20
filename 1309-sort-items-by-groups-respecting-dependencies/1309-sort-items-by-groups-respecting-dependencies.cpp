class Solution {
    vector<int> topoSort(vector<unordered_set<int>>& graph, vector<int>& indegree) {
        vector<int> ans;
        queue<int> q;
        int V = indegree.size();
        for (int i=0; i<V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for (const int& it: graph[front]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        for (int i=0; i<V; i++) {
            if (indegree[i] > 0) {
                return {};
            }
        }
        return ans;
    }
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // group the isolated items to themselves
        for (int i=0; i<n; i++) {
            if (group[i] == -1) {
                group[i] = m++;
            }
        }
        // build the graph
        vector<unordered_set<int>> graphGroup(m), graphItem(n);
        vector<int> indegreeGroup(m), indegreeItem(n);
        for (int i=0; i<n; i++) {
            int toGroup = group[i];
            for (const int& from: beforeItems[i]) {
                int fromGroup = group[from];
                if (fromGroup != toGroup && graphGroup[fromGroup].count(toGroup) == 0) {
                    graphGroup[fromGroup].insert(toGroup);
                    indegreeGroup[toGroup]++;
                }
                if (graphItem[from].count(i) == 0) {
                    graphItem[from].insert(i);
                    indegreeItem[i]++;
                }
            }
        }
        // topological sort
        vector<int> sortedGroup = topoSort(graphGroup, indegreeGroup);
        vector<int> sortedItem = topoSort(graphItem, indegreeItem);

        if (sortedGroup.size() == 0 || sortedItem.size() == 0) {
            return {};
        }

        vector<vector<int>> groupToItem(m);
        for (const int& item: sortedItem) {
            groupToItem[group[item]].push_back(item);
        }

        vector<int> ans;
        for (const int& g: sortedGroup) {
            for (const int& item: groupToItem[g]) {
                ans.push_back(item);
            }
        }
        return ans;
    }
};