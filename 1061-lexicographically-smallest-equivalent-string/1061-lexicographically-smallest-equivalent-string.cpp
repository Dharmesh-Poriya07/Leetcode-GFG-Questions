class DSUByRank{
    private:
    int *parent;
    int *rank;
    int n;
    public:
    DSUByRank(int n){
        this->n = n;
        parent = new int[n];
        rank = new int[n]{0};
        for (int i = 0; i < n; i++)
            parent[i] = rank[i] = i;
    }

    int Find(int x){
        if(parent[x] == x) return x;
        return parent[x] = Find(parent[x]);
    }

    void Union(int x,int y){
        int x_root = Find(x);
        int y_root = Find(y);
        if(x_root == y_root) return;
        if(rank[x_root]<rank[y_root]){
            parent[y_root] = x_root;
        }else{
            parent[x_root] = y_root;
        }
    }

    bool isConnected(int x,int y){
        return Find(x)==Find(y);
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSUByRank dsu(26);
        for(int i=0;i<s1.size();i++){
            dsu.Union(s1[i]-'a',s2[i]-'a');
        }
        string ans = "";
        for (int i = 0; i < baseStr.size(); i++) {
            char ch = dsu.Find(baseStr[i]-'a') + 'a';
            ans.push_back(ch);
        }
        return ans;
    }
};