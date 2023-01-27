class Solution {
private:
    ListNode *dummy = new ListNode(0), *pre = dummy;
    int length(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head -> next;
        }
        return len;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        dummy -> next = head;
        int len = length(head);
        ListNode *current = head;
        for (int i = 0; i < len / k; i++) {
            ListNode *next,*prev,*temp;
            next = prev = nullptr;
            temp = current;
            for (int j = 0; j < k; j++) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            pre->next = prev;
            pre = temp;
        }
        pre->next = current;
        return dummy -> next;
    }
};