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
    ListNode *mergeTwoSortedLinkedList(ListNode *l1,ListNode *l2){
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode *newHead,*current1,*current2,*tail;
        newHead = tail = nullptr;
        current1 = l1;
        current2 = l2;
        if(current1->val <= current2->val){
            newHead = tail = current1;
            current1 = current1->next;
        }else{
            newHead = tail = current2;
            current2 = current2->next;
        }
        
        while(current1 and current2){
            if(current1->val<=current2->val){
                tail->next = current1;
                tail = current1;
                current1 = current1->next;
            }else{
                tail->next = current2;
                tail = current2;
                current2 = current2->next;
            }
        }
        if(current1) tail->next = current1;
        else tail->next = current2;
        return newHead;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        if(lists.size()==1) return lists.back();
        
        ListNode *prev = lists.front();
        for(int i=1;i<lists.size();i++){
            prev = mergeTwoSortedLinkedList(prev,lists[i]);
        }
        return prev;
    }
};