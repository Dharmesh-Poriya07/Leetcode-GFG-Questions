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
    int mxans;
    int helper(TreeNode *root){
        if(!root) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        int subtreepath = root->val+left+right;
        int mxpath = max(root->val,root->val+max(left,right));
        mxans = max(mxans,max(subtreepath,mxpath));
        return mxpath;
    }
public:
    int maxPathSum(TreeNode* root) {
        mxans = root->val;
        helper(root);
        return mxans;
    }
};