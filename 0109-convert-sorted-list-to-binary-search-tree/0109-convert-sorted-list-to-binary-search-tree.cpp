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
    ListNode *getMiddle(ListNode *head){
        ListNode *slow,*fast,*prev;
        slow = fast = head;
        prev = nullptr;
        while(fast and fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return prev;
    }
    TreeNode* binarySearch(ListNode *head){
        if(!head){
            return NULL;
        }
        auto mid = getMiddle(head);
        
        TreeNode *root;
        ListNode *temp;
        if(mid){
            root = new TreeNode(mid->next->val);
            temp = mid->next->next;
            mid->next = nullptr;
        }else{
            root =  new TreeNode(head->val);
            temp = head->next;
            head = nullptr;
        }
        root->left = binarySearch(head);
        root->right = binarySearch(temp);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // vector<int> num;
        // while(NULL!=head){
        //     num.push_back(head->val);
        //     head = head->next;
        // }
        TreeNode *root = binarySearch(head);
        return root;
    }
};