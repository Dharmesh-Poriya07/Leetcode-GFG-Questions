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
    int sum;
    void dfs(TreeNode *root,int csum){
        if(!root) return;
        if(!root->left and !root->right){
            csum *= 10;
            csum += root->val;
            sum += csum;
            return;
        }
        csum *= 10;
        csum += root->val;
        dfs(root->left,csum);
        dfs(root->right,csum);
    }
    int sumNumbers(TreeNode* root) {
        sum = 0;
        dfs(root,0);
        return sum;
    }
};