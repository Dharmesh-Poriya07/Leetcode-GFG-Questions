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
    bool isValidBST(TreeNode* root,long lowerbound=LONG_MAX,long upperbound=LONG_MIN) {
        if(!root) return true;

        bool left = isValidBST(root->left,root->val,upperbound);
        bool right = isValidBST(root->right,lowerbound,root->val);
        return left and right and root->val<lowerbound and root->val>upperbound;
    }
};