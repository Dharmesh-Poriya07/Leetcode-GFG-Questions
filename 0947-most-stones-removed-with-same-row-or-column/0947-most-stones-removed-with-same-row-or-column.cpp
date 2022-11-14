class DisjointSet{
    vector<int> parent,rank,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findUPar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u] ++;
        }
    }
    
    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int mxrow = 0;
        int mxcol = 0;
        for(auto it : stones){
            mxrow = max(mxrow,it[0]);
            mxcol = max(mxcol,it[1]);
        }
        
        DisjointSet ds(mxrow+mxcol+1);
        unordered_map<int,int> stonesNodes;
        
        for(auto it : stones){
            int noderow = it[0];
            int nodecol = mxrow+it[1]+1;
            ds.unionBySize(noderow,nodecol);
            stonesNodes[noderow] = 1;
            stonesNodes[nodecol] = 1;
        }
        
        int count = 0;
        for(auto it : stonesNodes){
            if(ds.findUPar(it.first)==it.first)
                count ++;
        }
        return n-count;
    }
};