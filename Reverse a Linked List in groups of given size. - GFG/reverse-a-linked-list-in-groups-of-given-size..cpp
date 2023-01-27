// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


 // } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    node *dummy = new node(0), *pre = dummy;
    int length(node *head)
    {
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        return len;
    }
    public:
    struct node *reverse (struct node *head, int k)
    { 
        dummy->next = head;
        int len = length(head);
        node *current = head;
        node *next, *prev, *temp;
        for (int i = 0; i < len / k; i++)
        {
            next = prev = nullptr;
            temp = current;
            for (int j = 0; j < k; j++)
            {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            pre->next = prev;
            pre = temp;
        }
        next = prev = nullptr;
        temp = current;
        while(current){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        pre->next = prev;
        return dummy->next;
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}

  // } Driver Code Ends