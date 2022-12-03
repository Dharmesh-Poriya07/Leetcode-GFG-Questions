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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> lot; // level order traversal
        queue<TreeNode *> q;
        if(nullptr!=root)
            q.push(root);
        while(!q.empty()){
            int size = q.size();
            lot.push_back({});
            while(size--){
                TreeNode *current = q.front();
                q.pop();
                lot.back().push_back(current->val);
                if(nullptr!=current->left) q.push(current->left);
                if(nullptr!=current->right) q.push(current->right);
            }
        }
        return lot;
    }
};