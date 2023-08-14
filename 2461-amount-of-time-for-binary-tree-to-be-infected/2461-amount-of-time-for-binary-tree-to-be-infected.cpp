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
    void findParents(TreeNode *root,unordered_map<int,TreeNode*> &parent){
        queue<TreeNode *> q;
        if(root) q.push(root);
        parent[root->val] = nullptr;
        while(!q.empty()){
            TreeNode *curr = q.front(); q.pop();
            if(curr->left){
                q.push(curr->left);
                parent[curr->left->val] = curr;
            }
            if(curr->right){
                q.push(curr->right);
                parent[curr->right->val] = curr;
            }
        }
    }
    TreeNode *findNode(TreeNode *root,int start){
        if(!root) return nullptr;

        if(start == root->val) return root;
        TreeNode *left = findNode(root->left,start);
        TreeNode *right = findNode(root->right,start);
        return left?left:right;
    }
    int burn(TreeNode *target,unordered_map<int,TreeNode*> &parent){
        queue<TreeNode *> q;
        q.push(target);
        unordered_map<int,int> vis;
        vis[target->val]++;
        int time = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode *curr = q.front(); q.pop();
                if(parent[curr->val] and vis[parent[curr->val]->val]==0){
                    vis[parent[curr->val]->val]++;
                    q.push(parent[curr->val]);
                }
                if(curr->left and vis[curr->left->val]==0){
                    vis[curr->left->val]++;
                    q.push(curr->left);
                }
                if(curr->right and vis[curr->right->val]==0){
                    vis[curr->right->val]++;
                    q.push(curr->right);
                }
            }
            time++;
        }
        return time-1;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,TreeNode*> parent;
        findParents(root,parent);
        TreeNode *target = findNode(root,start);
        int time = burn(target,parent);
        return time;
    }
};