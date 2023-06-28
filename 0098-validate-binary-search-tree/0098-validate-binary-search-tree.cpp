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
public:
    bool isBST(TreeNode *root,long lowerbound,long upperbound){
        if(!root) return true;

        bool left = isBST(root->left,root->val,upperbound);
        bool right = isBST(root->right,lowerbound,root->val);
        return left and right and root->val<lowerbound and root->val>upperbound;
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root,LONG_MAX,LONG_MIN);
    }
};