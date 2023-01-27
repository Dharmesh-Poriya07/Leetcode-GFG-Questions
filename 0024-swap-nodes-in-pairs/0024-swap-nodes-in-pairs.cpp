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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode *dummy = new ListNode(-1,head);
        ListNode *prev,*current;
        prev = dummy;
        current = head;
        while(current and current->next){
            prev->next = current->next;
            current->next = current->next->next;
            prev->next->next = current;
            prev = current;
            current = current->next;
        }
        prev->next = current;
        return dummy->next;
    }
};