/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int findLength(ListNode *head){
        int length=0;
        ListNode *current = head;
        while(current != NULL){
            length ++;
            current = current->next;
        }
        return length;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length1 = findLength(headA);
        int length2 = findLength(headB);
        if(length1==0 || length2==0)
            return NULL;
        int difference = abs(length1-length2);
        if(difference != 0){
            if(length1>length2){
                while(difference--){
                    headA = headA->next;
                }
            }else{
                while(difference--){
                    headB = headB->next;
                }
            }
        }
        while(headA and headB and headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};