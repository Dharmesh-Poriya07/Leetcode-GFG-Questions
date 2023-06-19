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
    int mxdia = 0;
    int solve(TreeNode *root){
        if(!root) return 0;
        int dia = 0;
        int left = solve(root->left);
        int right = solve(root->right);
        dia = 1+max(left,right);
        mxdia = max(mxdia,max(dia,left+right+1));
        return dia;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return mxdia-1;
    }
};