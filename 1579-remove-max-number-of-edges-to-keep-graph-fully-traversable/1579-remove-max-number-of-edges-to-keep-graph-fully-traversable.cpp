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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU *aliceDsu = new DSU(n+1);
        DSU *bobDsu = new DSU(n+1);
        
        int alice_edges, bob_edges, redudent_edges;
        alice_edges = bob_edges = redudent_edges = 0;
        
        for(auto e : edges){
            if(3==e[0]){
                if((aliceDsu->findParent(e[1]) != aliceDsu->findParent(e[2])) or (bobDsu->findParent(e[1]) != bobDsu->findParent(e[2]))){
                    aliceDsu->makeUnion(e[1],e[2]);
                    bobDsu->makeUnion(e[1],e[2]);
                    alice_edges ++;
                    bob_edges ++;
                }else{
                    redudent_edges ++;
                }
            }
        }
                   
        for(auto e : edges){
            if(e[0]==1){
                if(aliceDsu->findParent(e[1]) != aliceDsu->findParent(e[2])){
                    aliceDsu->makeUnion(e[1],e[2]);
                    alice_edges ++;
                }else{
                    redudent_edges ++;
                }
            }else if(e[0]==2){
                if(bobDsu->findParent(e[1]) != bobDsu->findParent(e[2])){
                    bobDsu->makeUnion(e[1],e[2]);
                    bob_edges ++;
                }else{
                    redudent_edges ++;
                }
            }
        }
                   
        return (alice_edges == n-1 and bob_edges == n-1)?redudent_edges:-1;
    }
};