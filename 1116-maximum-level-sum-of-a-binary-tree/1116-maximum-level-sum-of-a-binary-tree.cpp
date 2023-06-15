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
    int maxLevelSum(TreeNode* root) {
        long long mxsum = LONG_MIN;
        int level_count = 0;
        int level = 0;
        queue<TreeNode *> q;
        if(nullptr != root) q.push(root);
        while(!q.empty()){
            int sz = q.size();
            level_count++;
            long long levelsum = 0;
            while(sz--){
                TreeNode *current = q.front();
                q.pop();
                levelsum += current->val;
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            if(mxsum<levelsum){
                mxsum = levelsum;
                level = level_count;
            }
        }
        return level;
    }
};