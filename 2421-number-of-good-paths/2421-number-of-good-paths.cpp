class DSU{
    private:
    vector<int> parent;
    public:
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x,int y){
        int x_par = find(x);
        int y_par = find(y);
        if(x_par == y_par) return;
        parent[y_par] = x_par;
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),[&](vector<int> &a,vector<int> &b){
            return max(vals[a[0]],vals[a[1]])<max(vals[b[0]],vals[b[1]]);
        });
        
        int n = vals.size();
        int ans = n;
        DSU obj(n);
        
        vector<unordered_map<int,int>> freq(n);
        for(int i=0;i<n;i++){
            freq[i][vals[i]] = 1;
        }
        int mx,u,v,uparent,vparent;
        
        for(auto &curr : edges){
            u = curr[0];
            v = curr[1];
            mx = max(vals[u],vals[v]);
            uparent = obj.find(u);
            vparent = obj.find(v);
            obj.Union(u,v);
            ans += freq[uparent][mx]*freq[vparent][mx];
            freq[uparent][mx] += freq[vparent][mx];
            freq[vparent].erase(mx);
        }
        return ans;
    }
};