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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *dummy = new ListNode(-1,head);
        ListNode *itr = dummy;
        ListNode *current = head->next;
        while(current){
            bool flag = false;
            while(current and itr->next->val == current->val){
                flag = true;
                current = current->next;
            }
            if(flag) itr->next = current;
            else itr = itr->next;
            if(current) current = current->next;
        }
        return dummy->next;
    }
};