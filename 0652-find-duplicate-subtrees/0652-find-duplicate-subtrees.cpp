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
    public:
    unordered_map<string, int> um;
    vector<TreeNode*>ans;
    
    string dfs(TreeNode* root) {
        string s1 = "", s2 = "", curr = to_string(root->val);
        if (root -> left) {
            s1 = dfs(root->left);
        }
        if (root -> right) {
            s2 = dfs(root->right);
        }

        string t = curr + "l" + s1 + "r" + s2;
        um[t]++;
        if (um[t] == 2) {
            ans.push_back(root);
        }
        return t;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        
        return ans;
    }
};