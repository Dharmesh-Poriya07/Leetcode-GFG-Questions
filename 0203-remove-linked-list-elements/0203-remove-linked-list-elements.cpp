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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev,*newHead;
        prev = newHead = nullptr;
        while(head){
            if(head->val!=val){
                if(!prev) prev = newHead = head;
                else prev->next = head,prev = head;
            }
            head = head->next;
        }
        prev?prev->next = nullptr:0;
        return newHead;
    }
};