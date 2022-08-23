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
private:
    ListNode* findMiddleNode(ListNode* head){
        ListNode *slow, *fast;
        slow = fast = head;
        while(nullptr!=fast and nullptr!=fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode *head){
        ListNode *next,*prev,*current;
        next = prev = nullptr;
        current = head;
        while(nullptr!=current){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *left = head;
        ListNode *middle = findMiddleNode(head);
        ListNode *right = reverseList(middle);
        
        while(nullptr!=right){
            if(left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};