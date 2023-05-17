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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow,*fast;
        slow = fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev, *next, *current;
        prev = next = nullptr;
        current = head;
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {
        auto middle = middleNode(head);
        auto tail = reverseList(middle);
        
        int mx = 0;
        while(tail){
            mx = max(mx,head->val+tail->val);
            head = head->next;
            tail = tail->next;
        }
        return mx;
    }
};