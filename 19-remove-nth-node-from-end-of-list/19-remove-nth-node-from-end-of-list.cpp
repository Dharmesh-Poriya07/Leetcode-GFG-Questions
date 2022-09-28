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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast,*slow;
        slow = NULL;
        fast = head;
        n--;
        while(n--){
            fast = fast->next;
            if(fast == NULL) return head; 
        }
        while(fast->next != NULL){
            fast = fast->next;
            if(slow == NULL) slow = head;
            else slow = slow->next;
        }
        if(slow == NULL){
            ListNode *temp = head;
            head = head->next;
        }else{
            ListNode *temp = slow->next;
            slow->next = temp->next;
        }
        return head;
    }
};