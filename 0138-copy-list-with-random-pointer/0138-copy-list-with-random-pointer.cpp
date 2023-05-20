/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        
        // first step : create copy of each node and put it to right side        
        Node *itr = head;
        
        while(itr){
            Node *copy = new Node(itr->val);
            copy->next = itr->next;
            itr->next = copy;
            itr = copy->next;
        }
        
        // second step : now assign random pointer to newly created copy node
        itr = head;
        while(itr){
            if(itr->random) itr->next->random = itr->random->next;
            else itr->next->random = nullptr;
            itr = itr->next->next;
        }
        
        // third step : now diffrentiat old list and new list
        itr = head;
        Node *dummy = new Node(0);
        Node *clone = dummy;
        while(itr){
            clone->next = itr->next;
            itr->next = clone->next->next;
            clone = clone->next;
            itr = itr->next;
        }
        return dummy->next;
    }
};