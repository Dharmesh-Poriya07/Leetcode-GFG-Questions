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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode *> q;
        if(nullptr != root)
            q.push(root);
        vector<vector<int>> levels;
        while(!q.empty()){
            int levelsz = q.size();
            levels.push_back({});
            while(levelsz--){
                TreeNode *current = q.front();
                q.pop();
                levels.back().push_back(current->val);
                if(nullptr != current->left)
                    q.push(current->left);
                if(nullptr!=current->right)
                    q.push(current->right);
            }
        }
        reverse(levels.begin(),levels.end());
        return levels;
    }
};