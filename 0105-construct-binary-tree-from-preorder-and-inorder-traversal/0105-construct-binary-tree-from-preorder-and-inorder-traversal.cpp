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
    int ind;
    TreeNode *tree(vector<int>& pre, vector<int>& in, int left,int right){
        if(left>right) return nullptr;

        TreeNode *root = new TreeNode(pre[ind++]);
        int cind = -1;
        for(int i=left;i<=right;i++){
            if(pre[ind-1]==in[i]){
                cind = i;
                break;
            }
        }
        root->left = tree(pre,in,left,cind-1);
        root->right = tree(pre,in,cind+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        ind = 0;
        return tree(preorder,inorder,0,inorder.size()-1);
    }
};