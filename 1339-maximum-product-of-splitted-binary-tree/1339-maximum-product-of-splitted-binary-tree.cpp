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
    int sumOfNodes(TreeNode *root){
        if(!root) return 0;
        return sumOfNodes(root->left)+sumOfNodes(root->right)+root->val;
    }
    long long ans;
    long long total_sum;
    int helper(TreeNode *root){
        if(!root) return 0;
        long long left = helper(root->left);
        long long right = helper(root->right);
        ans = max(ans,max((total_sum-left)*left,(total_sum-right)*right));
        return left+right+root->val;
    }
public:
    int maxProduct(TreeNode* root) {
        ans = 0;
        total_sum = sumOfNodes(root);
        int temp = helper(root);
        return ans%1000000007;
    }
};