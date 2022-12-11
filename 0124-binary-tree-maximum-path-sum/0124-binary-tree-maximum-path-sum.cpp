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
        int temp = max(root->val,max(root->val+left,root->val+right));
        mxans = max(mxans,max(root->val+left+right,temp));
        return temp;
    }
public:
    int maxPathSum(TreeNode* root) {
        mxans = INT_MIN;
        helper(root);
        return mxans;
    }
};