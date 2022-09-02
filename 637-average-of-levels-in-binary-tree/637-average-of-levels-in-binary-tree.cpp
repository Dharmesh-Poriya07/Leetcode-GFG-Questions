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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> ans;
        if(nullptr==root) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int sze = q.size();
            int temp_sze = sze;
            double sum = 0.0;
            while(sze--){
                TreeNode *current = q.front();
                q.pop();
                sum += current->val;
                if(nullptr != current->left) q.push(current->left);
                if(nullptr!=current->right) q.push(current->right);
            }
            ans.push_back(sum/temp_sze);
        }
        return ans;
    }
};