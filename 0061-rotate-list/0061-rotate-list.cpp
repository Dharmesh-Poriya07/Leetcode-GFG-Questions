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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next or 0==k) return head;
        
        int len = 1;
        ListNode *curr = head;
        while(curr->next){
            len ++;
            curr = curr->next;
        }
        
        curr->next = head;
        
        k %= len;
        k = len-k;
        
        while(k--){
            curr = curr->next;
        }
        head = curr->next;
        curr->next = nullptr;
        return head;
    }
};