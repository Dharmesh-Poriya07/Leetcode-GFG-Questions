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
    string tree2str(TreeNode* root) {
        if(nullptr==root)
            return "";
        string ans = "";
        ans = to_string(root->val);
        string left="",right="";
        if(nullptr!=root->left){
            left.push_back('(');
            left += tree2str(root->left);
            left.push_back(')');
        }else if(nullptr!=root->right){
            left.push_back('(');
            left.push_back(')');
        }
        
        if(nullptr!=root->right){
            right.push_back('(');
            right += tree2str(root->right);
            right.push_back(')');
        }
        ans += left+right;
        return ans;
    }
};