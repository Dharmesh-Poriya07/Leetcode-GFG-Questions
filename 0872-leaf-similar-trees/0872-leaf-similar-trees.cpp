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
    vector<int> getLeafs(TreeNode *root){
        if(!root) return {};
        if(!root->left and !root->right) return {root->val};
        vector<int> left = getLeafs(root->left);
        vector<int> right = getLeafs(root->right);
        for(auto leaf : right) left.push_back(leaf);
        return left;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return getLeafs(root1)==getLeafs(root2);
    }
};