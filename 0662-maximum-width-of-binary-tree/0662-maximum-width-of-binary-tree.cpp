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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode *,unsigned>> q;
        if(nullptr != root)
            q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int mn = q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                unsigned curr_id = q.front().second-mn;
                TreeNode *current = q.front().first;
                q.pop();
                if(0==i) first = curr_id;
                if(size-1==i) last = curr_id;
                if(nullptr != current->left) q.push({current->left,curr_id*2+1});
                if(nullptr != current->right) q.push({current->right,curr_id*2+2});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};