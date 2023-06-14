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
    int mindiff;
    TreeNode *prev;
    void solve(TreeNode *root){
        if(!root) return;

        solve(root->left);
        if(prev) mindiff = min(mindiff,abs(root->val-prev->val));

        prev = root;
        solve(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        mindiff = INT_MAX;
        prev = nullptr;
        solve(root);
        return mindiff;
    }
};