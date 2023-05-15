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
    int length(ListNode *head){
        int count = 0;
        ListNode *curr = head;
        while(curr){
            count ++;
            curr = curr->next;
        }
        return count;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int len = length(head);
        int pos1 = k-1;
        int pos2 = len-k;
        ListNode *node1,*node2,*curr = head;
        while(0<=pos1 || 0<=pos2){
            if(0==pos1){
                node1 = curr;
            }
            if(0==pos2){
                node2 = curr;
            }
            pos1--;
            pos2--;
            curr = curr->next;
        }
        swap(node1->val,node2->val);
        return head;
    }
};