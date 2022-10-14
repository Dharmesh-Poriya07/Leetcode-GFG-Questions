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
    ListNode *findMid(ListNode *head){
        ListNode *slow,*fast;
        slow = fast = head;
        while(nullptr!=fast and nullptr!=fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(nullptr==head->next) return nullptr;
        if(nullptr==head->next->next){
            head->next = nullptr;
            return head;
        }
        ListNode *mid = findMid(head);
        mid->val = mid->next->val;
        mid->next = mid->next->next;
        return head;
    }
};