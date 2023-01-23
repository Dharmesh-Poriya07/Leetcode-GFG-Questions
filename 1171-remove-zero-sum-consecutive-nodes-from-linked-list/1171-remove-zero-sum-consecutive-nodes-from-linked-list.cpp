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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return head;
        ListNode *dummy = new ListNode(0,head);
        map<int,ListNode *> hm;
        hm[0] = dummy;
        ListNode *current = head;
        int presum = 0;
        while(current){
            presum += current->val;
            if(hm.end()!=hm.find(presum)){
                int sum = presum;
                ListNode *temp = hm[presum]->next;
                while(temp!=current){
                    sum += temp->val;
                    hm.erase(sum);
                    temp = temp->next;
                }
                hm[presum]->next = current->next;
            }else{
                hm[presum] = current;
            }
            current = current->next;
        }
        return dummy->next;
    }
};