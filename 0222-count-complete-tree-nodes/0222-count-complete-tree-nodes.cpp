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
    int findLeftHeight(TreeNode *root){
        int height = 0;
        while(nullptr!=root){
            height ++;
            root = root->left;
        }
        return height;
    }
    int findRightHeight(TreeNode *root){
        int height = 0;
        while(nullptr!=root){
            height ++;
            root = root->right;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        if(nullptr == root) return 0;
        int leftH = findLeftHeight(root);
        int rightH = findRightHeight(root);
        
        if(leftH == rightH) return (1<<leftH)-1;
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};