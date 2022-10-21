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
    int goodNodes(TreeNode* root,int mx=INT_MIN) {
        if(nullptr==root)
            return 0;
        int count = 0;
        int cmx = max(mx,root->val); // current max
        if(root->val==cmx)
            count ++;
        count += goodNodes(root->left,cmx);
        count += goodNodes(root->right,cmx);
        return count;
    }
};