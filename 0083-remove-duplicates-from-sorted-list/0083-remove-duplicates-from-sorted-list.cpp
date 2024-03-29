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
        
        ListNode *current = head->next;
        ListNode *prev = head;
        
        while(current){
            if(prev->val != current->val)
                prev = prev->next = current;
            current = current->next;
        }
        prev->next = nullptr;
        return head;
    }
};