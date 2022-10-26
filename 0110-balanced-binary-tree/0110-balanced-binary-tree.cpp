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
    int height(TreeNode *root){
        if(nullptr==root) return 0;
        return 1+max(height(root->left),height(root->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if (nullptr == root) return true;
        int left = height(root->left);
        int right = height(root->right);
        if(2<=abs(left-right)) return false;
        return (isBalanced(root->left) and isBalanced(root->right));
    }
};