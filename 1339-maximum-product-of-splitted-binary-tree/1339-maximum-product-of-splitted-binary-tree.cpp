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
    int helper(TreeNode *root,long long tsum){
        if(!root) return 0;
        long long left = helper(root->left,tsum);
        long long right = helper(root->right,tsum);
        long long t1 = (tsum-left)*left;
        long long t2 = (tsum-right)*right;
        ans = max(ans,max(t1,t2));
        return left+right+root->val;
    }
public:
    int maxProduct(TreeNode* root) {
        ans = 0;
        long long total_sum = sumOfNodes(root);
        int temp = helper(root,total_sum);
        return ans%1000000007;
    }
};