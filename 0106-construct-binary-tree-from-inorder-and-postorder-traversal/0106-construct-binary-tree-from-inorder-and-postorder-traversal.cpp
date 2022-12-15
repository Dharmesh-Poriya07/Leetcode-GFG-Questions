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
    int postIndex;
    TreeNode *treeFromPostAndIn(vector<int>& inorder, vector<int>& postorder,int istart,int iend){
        if(istart>iend) return nullptr;
        
        TreeNode *root = new TreeNode(postorder[postIndex--]);
        int inIndex;
        for(int i=istart;i<=iend;i++){
            if(inorder[i]==postorder[postIndex+1]){
                inIndex = i;
                break;
            }
        }
        root->right = treeFromPostAndIn(inorder,postorder,inIndex+1,iend);
        root->left = treeFromPostAndIn(inorder,postorder,istart,inIndex-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = inorder.size()-1;
        return treeFromPostAndIn(inorder,postorder,0,postIndex);
    }
};