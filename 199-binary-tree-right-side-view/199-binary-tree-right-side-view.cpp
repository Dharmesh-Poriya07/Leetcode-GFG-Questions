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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode *> q;
        if(nullptr!=root)
            q.push(root);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode *current = q.front();
                q.pop();
                if(0==sz){
                    ans.push_back(current->val);
                }
                if(nullptr!=current->left) q.push(current->left);
                if(nullptr!=current->right) q.push(current->right);
            }
        }
        return ans;
    }
};