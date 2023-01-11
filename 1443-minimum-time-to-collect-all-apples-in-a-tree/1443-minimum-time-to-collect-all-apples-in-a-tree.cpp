class Solution {
private:
    int dfs(vector<vector<int>> &tree,vector<bool>& hasApple,vector<bool> &vis,int src,int current){
        int temp=0;
        bool flag = false;
        vis[src] = true;
        for(auto childs : tree[src]){
            if(!vis[childs]){
                temp = dfs(tree,hasApple,vis,childs,current+1);
                if(0!=temp){
                    flag = true;
                    current = temp;
                }
            }
        }
        if(temp>0 or hasApple[src] or flag) return current+1;
        return 0;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> tree(n);
        vector<bool> vis(n,false);
        for(auto e : edges) tree[e[0]].push_back(e[1]),tree[e[1]].push_back(e[0]);
        int ans = dfs(tree,hasApple,vis,0,0);
        return (0==ans)?0:ans-1;
    }
};