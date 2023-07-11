/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode *root,int k,vector<int> &ans){
        if(!root or k<0) return;
        if(0==k){
            ans.push_back(root->val);
            return;
        }

        solve(root->left,k-1,ans);
        solve(root->right,k-1,ans);
    }
    TreeNode *swapPointers(TreeNode *root,TreeNode *target,bool &flag){
        if(!root) return nullptr;
        if(root==target){
            root->left = root->right = nullptr;
            flag = true;
            return root;
        }

        auto left = swapPointers(root->left,target,flag);
        auto right = swapPointers(root->right,target,flag);

        if(left){
            if(flag){
                left->left = root;
            }else{
                left->right = root;
            }
            root->left = nullptr;
            flag = true;
            return root;
        }else if(right){
            if(flag){
                right->left = root;
            }else{
                right->right = root;
            }
            root->right = nullptr;
            flag = false;
            return root;
        }
        return nullptr;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        solve(target,k,ans);
        bool f = true;
        if(k>0){
            swapPointers(root,target,f);
            solve(target,k,ans);
        }
        
        return ans;
    }
};