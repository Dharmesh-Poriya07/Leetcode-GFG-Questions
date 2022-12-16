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
    TreeNode *helper(vector<int>& preorder, vector<int>& postorder,int prestart,int preend,int poststart,int postend){
        if(prestart > preend) return nullptr;
        
        TreeNode *root = new TreeNode(preorder[prestart]);
        
        if(preend==prestart) return root;
        int idx = poststart;
        while(postorder[idx] != preorder[prestart+1]) idx++;
        
        int total_ele = idx-poststart+1;
        root->left = helper(preorder,postorder,prestart+1,prestart+total_ele,poststart,idx);
        root->right = helper(preorder,postorder,prestart+total_ele+1,preend,idx+1,postend-1);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return helper(preorder,postorder,0,preorder.size()-1,0,preorder.size()-1);
    }
};