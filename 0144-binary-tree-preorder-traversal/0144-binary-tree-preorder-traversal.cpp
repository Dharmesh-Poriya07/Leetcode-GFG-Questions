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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,int>> st;
        if(root) st.push({root,1});
        vector<int> ans;
        while(!st.empty()){
            if(1==st.top().second){
                ans.push_back(st.top().first->val);
                st.top().second++;
                if(st.top().first->left) st.push({st.top().first->left,1});
            }else if(2==st.top().second){
                st.top().second++;
                if(st.top().first->right) st.push({st.top().first->right,1});
            }else{
                st.pop();
            }
        }
        return ans;
    }
};