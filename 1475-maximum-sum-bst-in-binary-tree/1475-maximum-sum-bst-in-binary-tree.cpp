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
class NodeValue{
    public :
    int mxsize,maxval,minval;
    NodeValue(int s,int mxv,int mnv){
        mxsize = s;
        maxval = mxv;
        minval = mnv;
    }
};
int mx = 0;
class Solution {
public:
    vector<int> solve(TreeNode *root){
        if(!root) return {0,INT_MIN,INT_MAX};

        auto left = solve(root->left);
        auto right = solve(root->right);
        if(left[1]<root->val and right[2]>root->val){
            int sum = left[0]+right[0]+root->val;
            int lftmx = max(root->val,right[1]);
            int rghtmn = min(root->val,left[2]);
            
            mx = max(mx,sum);
            return {sum,lftmx,rghtmn};
        }
        int sum = max(left[0],right[0]);
        return {sum,INT_MAX,INT_MIN};
    }
    int maxSumBST(TreeNode* root) {
        mx = INT_MIN;
        solve(root);
        return mx<0?0:mx;
    }
};