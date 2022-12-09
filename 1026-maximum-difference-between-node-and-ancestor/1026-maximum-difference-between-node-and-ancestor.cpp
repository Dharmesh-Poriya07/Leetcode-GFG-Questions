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
    vector<int> helper(TreeNode *root){
        if(!root) return {};

        auto left = helper(root->left);
        auto right = helper(root->right);
        int mn,mx,diff=0;
        mn = mx = root->val;
        if(0!=left.size()){
            mn = min(mn,left[0]);
            mx = max(mx,left[1]);
            diff = max(left[2],max(abs(root->val-left[0]),abs(root->val-left[1])));
        }
        if(0!=right.size()){
            mn = min(mn,right[0]);
            mx = max(mx,right[1]);
            diff = max(max(diff,right[2]),max(abs(root->val-right[0]),abs(root->val-right[1])));
        }
        return {mn,mx,diff};
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        vector<int> mnmxdiff = helper(root);
        return mnmxdiff[2];
    }
};