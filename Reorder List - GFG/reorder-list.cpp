//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:
    Node* findMiddle(Node* head){
    Node *slow = head;
    Node *fast = head;
    while(nullptr!=fast && nullptr!=fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // for even # of nodes middle element is first element of right part
}

Node* reverseList(Node *head){
    Node *nxt,*prev,*current;
    nxt = prev = nullptr;
    current = head;
    while(nullptr!=current){
        nxt = current->next;
        current->next = prev;
        prev = current;
        current = nxt;
    }
    return prev;
}

void reorderList(Node* head) {
    Node *left = head;
    Node *middle = findMiddle(head);
    Node *right = reverseList(middle);
    
    Node *templeft,*tempright;
    templeft = tempright = nullptr;
    
    while(left!=right && nullptr!=left->next && nullptr!=right->next){
        templeft = left->next;
        tempright = right->next;
        left->next = right;
        right->next = templeft;
        
        left = templeft;
        right = tempright;
    }
}
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends