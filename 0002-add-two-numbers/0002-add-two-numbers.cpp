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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *current = nullptr;
        ListNode *l3 = nullptr;
        
        int carry = 0;
        while(l1 and l2){
            int d = l1->val+l2->val+carry;
            carry = d/10;
            d = d%10;
            ListNode *temp = new ListNode(d);
            if(nullptr==l3) l3 = temp;
            else current->next = temp;
            current = temp;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1){
            int d = l1->val + carry;
            carry = d/10;
            d = d%10;
            ListNode *temp = new ListNode(d);
            current->next = temp;
            current = temp;
            l1 = l1->next;
        }
        while(l2){
            int d = l2->val + carry;
            carry = d/10;
            d = d%10;
            ListNode *temp = new ListNode(d);
            current->next = temp;
            current = temp;
            l2 = l2->next;
        }
        if(0!=carry){
            ListNode *temp = new ListNode(carry);
            current->next = temp;
            current = temp;
        }
        return l3;
    }
};