class DSU {
public:
    vector<int>rank;
    vector<int>parent;
    
    DSU(int n) {
        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }
    
    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    
    void makeUnion(int x, int y) {
        int p1 = findParent(x), p2 = findParent(y);
        if (p1 != p2) {
            if (rank[p1] > rank[p2]) {
                parent[p2] = p1;
                rank[p1] += rank[p2];
            }
            else {
                parent[p1] = p2;
                rank[p2] += rank[p1];
            }
        }
    }
};

class Solution {
public:
    bool static compare(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int nq = queries.size(), ne = edgeList.size();
        vector<vector<int>>queriesWithIndex;
        for (int i = 0; i < nq; i++) {
            queriesWithIndex.push_back({queries[i][2], queries[i][0], queries[i][1], i});
        }
        
        sort(queriesWithIndex.begin(), queriesWithIndex.end());
        sort(edgeList.begin(), edgeList.end(), compare);
        vector<bool>ans(nq, false);
        int currentEdgeIndex = 0;
        DSU dsu(n);

        for (auto q : queriesWithIndex) {
            int n1 = q[1], n2 = q[2], limit = q[0], idx = q[3];

            while (currentEdgeIndex < ne && edgeList[currentEdgeIndex][2] < limit) {
                int node1 = edgeList[currentEdgeIndex][0], node2 = edgeList[currentEdgeIndex][1];
                dsu.makeUnion(node1, node2);
                currentEdgeIndex++;
            }

            int p1 = dsu.findParent(n1), p2 = dsu.findParent(n2);
            ans[idx] = p1==p2;
        }

        return ans;
    }
};