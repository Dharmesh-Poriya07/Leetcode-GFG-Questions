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
    map<int,map<int,multiset<int>>> mp;
    void helper(TreeNode *root,int ind,int level){
        if(nullptr==root) return;
        mp[ind][level].insert(root->val);
        helper(root->left,ind-1,level+1);
        helper(root->right,ind+1,level+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> vt;
        
        helper(root,0,0);
        
        for(auto i : mp){
            vector<int> temp;
            for(auto j : i.second){
                for(auto k : j.second)
                    temp.push_back(k);
            }
            vt.push_back(temp);
        }
        return vt;
    }
};