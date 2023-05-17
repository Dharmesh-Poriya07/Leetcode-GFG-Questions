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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        
        ListNode *head = nullptr;
        ListNode *temp = nullptr;
        if(list1->val < list2->val){
            head = list1;
            temp = list1;
            list1 = list1->next;
        }else{
            head = list2;
            temp = list2;
            list2 = list2->next;
        }
        
        while(list1 and list2){
            if(list1->val < list2->val){
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            }else{
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
        }
        
        if(list1){
            temp->next = list1;
        }else{
            temp->next = list2;
        }
        return head;
    }
};