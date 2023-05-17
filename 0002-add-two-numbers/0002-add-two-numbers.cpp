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
        while(l1 or l2){
            int d = carry;
            if(l1){
                d += l1->val;
                l1 = l1->next;
            }
            
            if(l2){
                d += l2->val;
                l2 = l2->next;
            }
            
            carry = d/10;
            d %= 10;
            ListNode *temp = new ListNode(d);
            if(nullptr==l3) l3 = temp;
            else current->next = temp;
            current = temp;
        }
        
        if(0!=carry){
            ListNode *temp = new ListNode(carry);
            current->next = temp;
            current = temp;
        }
        return l3;
    }
};