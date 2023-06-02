// Disjoint Set
class DisjointSet{
    vector<int> parent,rank,size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
           parent[i] = i; 
           rank[i] = 0;
           size[i] = 1;
        } 
    }
    
    int findParent(int x){
        if(x == parent[x]) return x;
        return parent[x] = findParent(parent[x]);
    }
    
    void unionByRank(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);
        
        if(pu==pv) return;
        
        if(rank[pu] < rank[pv]) parent[pu] = pv;
        else if(rank[pv] < rank[pu]) parent[pv] = pu;
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    
    void unionBySize(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);
        
        if(pu == pv) return;
        
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    int findNoOfParent(){
        int cnt = 0;
        for(int i=0;i<parent.size();i++)
            if(i==parent[i])
                cnt ++;
        return cnt;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> redundant;
        int n = edges.size();
        DisjointSet *dsu = new DisjointSet(n);

        for(auto &e : edges){
            int u = e[0], v = e[1];
            if(dsu->findParent(u) == dsu->findParent(v)) redundant = e;
            else dsu->unionByRank(u,v);
        }
        return redundant;
    }
};