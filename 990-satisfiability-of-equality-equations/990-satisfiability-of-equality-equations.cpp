class Solution {
private:
    vector<int> parent,rank;
    int Find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = Find(parent[x]);
    }
    
    void Union(int x,int y){
        int lx = Find(x);
        int ly = Find(y);
        
        if(lx != ly){
            if(rank[lx]>rank[ly]){
                parent[ly] = lx;
            }else if(rank[lx]<rank[ly]){
                parent[lx] = ly;
            }else{
                parent[lx] = ly;
                rank[ly] ++;
            }
        }
    }
public:
    bool equationsPossible(vector<string>& equations) {
        parent = vector<int>(26);
        rank = vector<int>(26);
        for(int i=0;i<26;i++){
            parent[i] = i;
            rank[i] = 1;
        }
        
        for(string eq : equations){
            if('=' == eq[1]){
                Union(eq[0]-'a',eq[3]-'a');
            }
        }
        
        for(string eq : equations){
            if('!' == eq[1]){
                int lx = Find(eq[0]-'a');
                int ly = Find(eq[3]-'a');
                if(lx==ly)
                    return false;
            }
        }
        return true;
    }
};