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
        if(nullptr==root){
            return false;
        }
        if(nullptr==root->left and nullptr==root->right and currentSum+root->val==targetSum)
            return true;
        bool left = helper(root->left,currentSum+root->val,targetSum);
        bool right = helper(root->right,currentSum+root->val,targetSum);
        
        return (left or right);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(nullptr==root) return false;
        return helper(root,0,targetSum);
    }
};