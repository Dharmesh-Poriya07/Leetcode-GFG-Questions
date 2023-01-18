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
    pair<TreeNode*,bool> dfs(TreeNode *root,int limit,int sum){
        if(!root) return {nullptr,false};
        auto left = dfs(root->left,limit,sum+root->val);
        auto right = dfs(root->right,limit,sum+root->val);
        root->left = left.first;
        root->right = right.first;
        if(!root->left and !root->right and (left.second or right.second or sum+root->val<limit)){
            return {nullptr,true};
        }
        return {root,false};
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return dfs(root,limit,0).first;
    }
};