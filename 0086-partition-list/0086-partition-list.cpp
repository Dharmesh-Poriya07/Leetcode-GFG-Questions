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
    ListNode* partition(ListNode* head, int x) {
        if(nullptr==head || nullptr==head->next)
            return head;
        
        ListNode *ltx,*gtx,*cltx,*cgtx,*newHead,*current;
        ltx = gtx = cltx = cgtx = nullptr;
        newHead = head;
        current = head;
        while(nullptr!=current){
            if(current->val<x){
                if(nullptr==ltx){
                    newHead = ltx = cltx = current;
                }else{
                    cltx->next = current;
                    cltx = cltx->next;
                }
            }else{
                if(nullptr==gtx){
                    gtx = cgtx = current;
                }else{
                    cgtx->next = current;
                    cgtx = cgtx->next;
                }
            }
            current = current->next;
        }
        if(nullptr==ltx){
            newHead = gtx;
        }else{
            cltx->next = gtx;
            if(nullptr!=cgtx)
                cgtx->next = nullptr;
        }
        return newHead;
    }
};