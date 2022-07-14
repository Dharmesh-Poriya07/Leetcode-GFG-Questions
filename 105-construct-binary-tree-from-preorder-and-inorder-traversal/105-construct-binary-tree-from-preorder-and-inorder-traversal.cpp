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
    int preIndex;
    TreeNode *constructTree(vector<int>& preorder, vector<int>& inorder,int istart,int iend){
        if(istart>iend) return nullptr;
        
        TreeNode *root = new TreeNode(preorder[preIndex++]);
        
        int inindx = 0;
        for(int i=istart;i<=iend;i++){
            if(preorder[preIndex-1]==inorder[i]){
                inindx = i;
                break;
            }
        }
        root->left = constructTree(preorder,inorder,istart,inindx-1);
        root->right = constructTree(preorder,inorder,inindx+1,iend);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIndex = 0;
        return constructTree(preorder,inorder,0,inorder.size()-1);
    }
};