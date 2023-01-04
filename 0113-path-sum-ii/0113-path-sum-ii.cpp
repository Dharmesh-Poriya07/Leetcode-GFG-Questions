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
    vector<vector<int>> ans;
    vector<int> cp; //current path
    void helper(TreeNode *root,int ts,int cs){
        if(nullptr==root) return;
        
        cp.push_back(root->val);
        if(!root->left and !root->right){
            if(cs+root->val==ts) ans.push_back(cp);
            cp.pop_back();
            return;
        }
        helper(root->left,ts,cs+root->val);
        helper(root->right,ts,cs+root->val);
        cp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ans = vector<vector<int>>();
        cp = vector<int>();
        int currentSum = 0;
        helper(root,targetSum,currentSum);
        return ans;
    }
};