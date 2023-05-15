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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr1,*ptr2,*ptr3;
        ptr1 = ptr2 = ptr3 = head;
        
        while(ptr3){
            if(0>=k) ptr1 = ptr1->next;
            if(1<k) ptr2 = ptr2->next;
            ptr3 = ptr3->next;
            k--;
        }
        swap(ptr1->val,ptr2->val);
        return head;
    }
};