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
    bool isBal;
    int height(TreeNode *root){
        if(nullptr==root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        if(1<abs(left-right))
            isBal = false;
        return 1+max(left,right);
    }
public:
    bool isBalanced(TreeNode* root) {
        isBal = true;
        height(root);
        return isBal;
    }
};