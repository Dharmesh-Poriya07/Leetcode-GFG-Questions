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
            sum += (csum*10+root->val);
            return;
        }
        dfs(root->left,csum*10+root->val);
        dfs(root->right,csum*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        sum = 0;
        dfs(root,0);
        return sum;
    }
};