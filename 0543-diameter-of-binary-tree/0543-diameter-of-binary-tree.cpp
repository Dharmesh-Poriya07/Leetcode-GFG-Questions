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
    int dia;
int height(TreeNode *root){
    if(root == NULL){
        return 0;
    }
    int left_h = height(root->left);
    int right_h = height(root->right);
    dia = max(dia,left_h+right_h);
    return (max(left_h,right_h)+1);
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dia = INT_MIN;
        height(root);
        return dia;
    }
};