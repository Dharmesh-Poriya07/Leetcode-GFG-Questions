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
    unordered_map<int,int> elements;
    TreeNode *treeFromPreAndIn(vector<int>& preorder, vector<int>& inorder,int istart,int iend){
        if(istart > iend) return nullptr;
        
        TreeNode *root = new TreeNode(preorder[preIndex++]);
        int inindex = elements[preorder[preIndex-1]];
        root->left = treeFromPreAndIn(preorder,inorder,istart,inindex-1);
        root->right = treeFromPreAndIn(preorder,inorder,inindex+1,iend);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIndex = 0;
        for(int i=0;i<inorder.size();i++)
           elements[inorder[i]] = i;
        return treeFromPreAndIn(preorder,inorder,0,inorder.size()-1);
    }
};