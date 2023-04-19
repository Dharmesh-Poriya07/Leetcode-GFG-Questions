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
    int max_len = 0;
    void maxZigZag(TreeNode *root,int dir,int count){
        if(!root) return;
        max_len = max(max_len,count);
        if(dir==1){
            maxZigZag(root->left,2,count+1);
            maxZigZag(root->right,1,1);
        }else{
            maxZigZag(root->right,1,count+1);
            maxZigZag(root->left,2,1);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        maxZigZag(root,1,0);
        maxZigZag(root,2,0);
        return max_len;
    }
};