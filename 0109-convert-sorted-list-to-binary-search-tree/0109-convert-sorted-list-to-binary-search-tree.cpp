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
    TreeNode* binarySearch(vector<int> &num,long long int low,long long int high){
        if(low>high){
            return NULL;
        }
        int mid = low + (high-low)/2;
        
        TreeNode *root = new TreeNode(num[mid]);
        root->left = binarySearch(num,low,mid-1);
        root->right = binarySearch(num,mid+1,high);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> num;
        while(NULL!=head){
            num.push_back(head->val);
            head = head->next;
        }
        TreeNode *root = binarySearch(num,0,num.size()-1);
        return root;
    }
};