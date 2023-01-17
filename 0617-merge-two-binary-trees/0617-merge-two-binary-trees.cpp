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
    TreeNode *dfs(TreeNode *root1,TreeNode *root2){
        if(!root1 and !root2) return nullptr;
        
        int val;
        if(root1 and root2) val = root1->val+root2->val;
        else if(root1) val = root1->val;
        else val = root2->val;
        TreeNode *root = new TreeNode(val);
        
        root->left = dfs(root1?root1->left:root1,root2?root2->left:root2);
        root->right = dfs(root1?root1->right:root1,root2?root2->right:root2);
        return root;
    }
    
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return dfs(root1,root2);
    }
};