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
private:
    int total_paths = 0;
    vector<int> paths;
    void path(TreeNode *root,long csum,int targetsum){
        if(!root) return;
        
        paths.push_back(root->val);
        path(root->left,csum,targetsum);
        path(root->right,csum,targetsum);
        long sum = 0;
        for (int j = paths.size() - 1; j >= 0; j--) {
            sum += paths[j];
            if (sum == (long)targetsum)
                total_paths++;
        }
        paths.pop_back();
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        paths = vector<int>();
        path(root,0,targetSum);
        return total_paths;
    }
};