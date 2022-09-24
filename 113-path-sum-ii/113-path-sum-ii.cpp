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
    void helper(TreeNode *root,int ts,int cs,vector<int> &cp,vector<vector<int>> &ans){
        if(nullptr==root) return;
        if(nullptr==root->left and nullptr==root->right){
            if(cs+root->val == ts){
                cp.push_back(root->val);
                ans.push_back(cp);
                cp.pop_back();
            }
            return;
        }
        
        cp.push_back(root->val);
        helper(root->left,ts,cs+root->val,cp,ans);
        helper(root->right,ts,cs+root->val,cp,ans);
        cp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> currentPath;
        int currentSum = 0;
        helper(root,targetSum,currentSum,currentPath,ans);
        return ans;
    }
};