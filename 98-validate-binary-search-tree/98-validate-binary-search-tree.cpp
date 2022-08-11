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
class IsBst{
    public:
    bool isBst;
    long long mx,mn;
};
class Solution {
private:
    IsBst* helper(TreeNode *root){
        if(nullptr==root){
            IsBst *ibst = new IsBst();
            ibst->isBst = true;
            ibst->mx = LLONG_MIN;
            ibst->mn = LLONG_MAX;
            return ibst;
        }
        IsBst *left = helper(root->left);
        IsBst *right = helper(root->right);
        
        IsBst *current = new IsBst();
        current->isBst = (long long)root->val>left->mx && (long long)root->val<right->mn && left->isBst && right->isBst;
        current->mx = max((long long)root->val,max(left->mx,right->mx));
        current->mn = min((long long)root->val,min(left->mn,right->mn));
        return current;
    }
public:
    bool isValidBST(TreeNode* root) {
        IsBst *ans = helper(root);
        return ans->isBst;
    }
};