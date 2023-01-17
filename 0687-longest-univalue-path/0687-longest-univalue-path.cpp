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
    int longestpath;
    pair<int,int> helper(TreeNode *root){
        if(!root) return {0,-1};
        
        pair<int,int> ans = {1,root->val};
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        if(left.second==root->val and right.second==root->val){
            longestpath = max(longestpath,left.first+right.first+1);
            ans.first = max(left.first,right.first)+1;
            ans.second = root->val;
        }else if(left.second==root->val){
            longestpath = max(longestpath,left.first+1);
            ans.first = left.first+1;
            ans.second = root->val;
        }else if(right.second==root->val){
            longestpath = max(longestpath,right.first+1);
            ans.first = right.first+1;
            ans.second = root->val;
        }
        return ans;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        longestpath = 0;
        helper(root);
        return longestpath==0?0:longestpath-1;
    }
};