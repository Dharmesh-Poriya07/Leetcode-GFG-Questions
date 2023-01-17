/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> pathnodes;
    vector<int> listnodes;
    void ln(ListNode *head){
        while(head){
            listnodes.push_back(head->val);
            head = head->next;
        }
    }
    bool dfs(TreeNode *root){
        if(!root) return false;
        pathnodes.push_back(root->val);
        
        bool ans = dfs(root->left) or dfs(root->right);
        int i= listnodes.size()-1;
        for(int j=pathnodes.size()-1;0<=i and 0<=j;j--,i--)
            if(pathnodes[j]!=listnodes[i])
                break;
        
        if(-1==i) return true;
        pathnodes.pop_back();
        return ans;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        pathnodes = vector<int>();
        listnodes = vector<int>();
        ln(head);
        return dfs(root);
    }
};