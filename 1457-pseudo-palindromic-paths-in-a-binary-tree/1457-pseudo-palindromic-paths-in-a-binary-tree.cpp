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
    void countPseudoPalindromicPaths(TreeNode *root,vector<int> &digits,int &count){
        if(nullptr==root)
            return;
        
        digits[root->val]++;
        countPseudoPalindromicPaths(root->left,digits,count);
        countPseudoPalindromicPaths(root->right,digits,count);
        
        if(nullptr==root->left and nullptr==root->right){
            int flag = 0;
            for(int i : digits){
                if(0!=i%2){
                    flag ++;
                }
            }
            if(0==flag || flag==1){
                count ++;
            }
        }
        digits[root->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> digits(10,0);
        int count = 0;
        countPseudoPalindromicPaths(root,digits,count);
        return count;
    }
};