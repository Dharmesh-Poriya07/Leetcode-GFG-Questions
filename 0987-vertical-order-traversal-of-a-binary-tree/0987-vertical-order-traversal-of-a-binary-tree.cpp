/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    map<int,map<int,multiset<int>>> mp;
    void dfs(TreeNode *root,int x,int level){
        if(nullptr==root) 
            return;
        mp[x][level].insert(root->val);
        dfs(root->left,x-1,level+1);
        dfs(root->right,x+1,level+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        vector<vector<int>> vt(mp.size());
        int i=0;
        for(auto x : mp){
            for(auto y : x.second)
                for(auto val : y.second)
                    vt[i].push_back(val);
            i++;
        }
        return vt;
    }
};