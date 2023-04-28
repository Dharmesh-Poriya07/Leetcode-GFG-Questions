class DSUByRank{
    public:
    int *parent;
    int n;
    DSUByRank(int n){
        this->n = n;
        parent = new int[n];
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int Find(int x){
        if(parent[x] == x) return x;
        return parent[x] = Find(parent[x]);
    }

    void Union(int x,int y){
        int x_root = Find(x);
        int y_root = Find(y);
        if(x_root != y_root) {
            parent[x_root] = y_root;
            n--;
        }
    }
    int size(){
        return n;
    }
};
class Solution {
public:
    bool isEqual(string &s1,string &s2){
        int count_diff = 0;
        
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])
                count_diff ++;
        }
        return (0==count_diff or 2==count_diff);
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        
        DSUByRank *dsu = new DSUByRank(n);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isEqual(strs[i],strs[j])){
                    dsu->Union(i,j);
                }
            }
        }
        
        return dsu->size();
    }
};