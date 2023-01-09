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
    int path(TreeNode *root,long csum,int targetsum){
        if(!root) return 0;
        int ans = 0;
        csum += root->val;
        if(csum==targetsum) ans++;
        ans += path(root->left,csum,targetsum);
        ans += path(root->right,csum,targetsum);
        return ans;
    }
    int helper(TreeNode *root,int targetsum){
        if(!root) return 0;
        
        return path(root,0,targetsum)+helper(root->left,targetsum)+helper(root->right,targetsum);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        return helper(root,targetSum);
    }
};