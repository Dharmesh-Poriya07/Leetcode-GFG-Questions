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
        if(!head or !head->next or left==right) return head;
        ListNode *firsttail,*current,*subprev,*subnext;
        firsttail = subprev = subnext = nullptr;
        current = head;
        int nodes = right-left+1;
        left--;
        while(left--){
            firsttail = current;
            current = current->next;
        }
        while (nodes and current)
        {
            subnext = current->next;
            current->next = subprev;
            subprev = current;
            current = subnext;
            nodes --;
        }
        
        if(!firsttail){
            head->next = current;
            head = subprev;
        }else{
            firsttail->next->next = current;
            firsttail->next = subprev;
        }
        return head;
    }
};