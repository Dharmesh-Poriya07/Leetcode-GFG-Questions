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
        if(root)
            q.push(root);
        while(!q.empty()){
            int sz = q.size();
            ans.push_back(q.front()->val);
            while(sz--){
                TreeNode *current = q.front();
                q.pop();
                if(current->right) q.push(current->right);
                if(current->left) q.push(current->left);
            }
        }
        return ans;
    }
};