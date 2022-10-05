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
    void helper(TreeNode* root,int val,int cdepth,int depth){
        if(nullptr==root) return;
        if(cdepth==depth-1){
            TreeNode * nnode = new TreeNode(val);
            nnode->left = root->left;
            root->left = nnode;
            nnode = new TreeNode(val);
            nnode->right = root->right;
            root->right = nnode;
            return;
        }
        helper(root->left,val,cdepth+1,depth);
        helper(root->right,val,cdepth+1,depth);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(1==depth){
            TreeNode *newnode = new TreeNode(val,root,nullptr);
            return newnode;
        }
        helper(root,val,1,depth);
        return root;
    }
};