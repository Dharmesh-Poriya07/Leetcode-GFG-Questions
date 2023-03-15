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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode *> q;
        if(root) q.push(root);
        bool leaf_found = false;
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            if(leaf_found and (curr->left or curr->right)) return false;
            if(!curr->left and curr->right) return false;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            else leaf_found = true;
        }
        return true;
    }
};