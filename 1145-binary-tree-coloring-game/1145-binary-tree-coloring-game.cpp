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
    int countTotalNodes(TreeNode *root){
        if(!root) return 0;
        return 1+countTotalNodes(root->left)+countTotalNodes(root->right);
    }
    TreeNode *findNode(TreeNode *root,int x){
        if(!root) return nullptr;
        if(root->val==x) return root;
        TreeNode *left = findNode(root->left,x);
        if(left) return left;
        return findNode(root->right,x);
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int total = countTotalNodes(root);
        // cout<<total<<endl;
        TreeNode *nodex = findNode(root,x);
        // cout<<nodex->val<<endl;
        int xleft = countTotalNodes(nodex->left);
        int xright = countTotalNodes(nodex->right);
        // cout<<xleft<<" "<<xright<<endl;
        
        int diff = total-xleft-xright-1;
        if(diff>xleft+xright+1) return true;
        if(xleft>xright+1+diff) return true;
        if(xright>xleft+1+diff) return true;
        return false;
    }
};