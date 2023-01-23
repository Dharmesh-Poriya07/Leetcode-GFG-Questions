//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    Node* reverseList(struct Node *head)
    {
        Node *_prev,*_current,*_next;
        _next = _prev = NULL;
        _current = head;
        while(_current){
            _next = _current->next;
            _current->next = _prev;
            _prev = _current;
            _current = _next;
        }
        return _prev;
    }
    public:
    Node *compute(Node *head)
    {
        if(!head or !head->next) return head;
        head = reverseList(head);
        Node *current = head->next;
        Node *prev = head;
        while(current){
            if(prev->data <= current->data)
                prev = prev->next = current;
            current = current->next;
        }
        prev->next = NULL;
        return reverseList(head);
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends