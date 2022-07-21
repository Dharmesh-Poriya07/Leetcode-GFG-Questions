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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(nullptr==head || nullptr==head->next)
            return head;
        ListNode *current = head;
        ListNode *newHead = head;
        ListNode *left1,*left2,*right1,*right2;
        left1 = current;
        left2 = right1 = right2 = nullptr;
        
        int count = 1;
        while(nullptr!=current && count!=left){
            left1 = current;
            count ++;
            current = current->next;
        }
        if(nullptr==current){
            return head;
        }
        left2 = current;
        ListNode *next,*prev;
        next = prev = nullptr;
        while(count != right+1){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        right1 = prev;
        right2 = next;
        
        if(left2==head){
            newHead = right1;
            left1->next = right2;
        }else{
            left1->next = right1;
            left2->next = right2;
        }
        return newHead;
    }
};