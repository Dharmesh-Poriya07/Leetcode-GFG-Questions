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
    bool helper(TreeNode* root,int currentSum, int targetSum){
        if(nullptr==root) return false;
        
        if(!root->left and !root->right and currentSum+root->val==targetSum) return true;
        
        return (helper(root->left,currentSum+root->val,targetSum) or helper(root->right,currentSum+root->val,targetSum));
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(nullptr==root) return false;
        return helper(root,0,targetSum);
    }
};