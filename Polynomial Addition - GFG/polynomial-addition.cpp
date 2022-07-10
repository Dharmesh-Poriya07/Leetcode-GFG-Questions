// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};


void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data, int new_data1)
{
    struct Node* new_node = new Node(new_data, new_data1);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    
    while (temp != NULL)
    {
       printf("%d %d ", temp->coeff, temp->pow);
       temp  = temp->next;
    }
}

Node* addPolynomial(Node *p1, Node *p2);


void create_node(int x, int y, struct Node **temp)
{
    struct Node *r, *z;
    z = *temp;
    if(z == NULL)
    {
        r = new Node(x, y);
        *temp = r;
        r->next = NULL;
    }
    else
    {
        r->next = new Node(x, y);
        r = r->next;
        r->next = NULL;
    }
}
 

/* Driver program to test above function*/

 // } Driver Code Ends
/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};
*/

class Solution{
  public:
    /* The below method print the required sum of polynomial
    p1 and p2 as specified in output  */
    Node* addPolynomial(Node *p1, Node *p2)
    {
        if(nullptr==p1) return p2;
        if(nullptr==p2) return p1;
        Node *head = nullptr;
        Node *current1 = p1;
        Node *current2 = p2;
        Node *prev = nullptr;
        if(current2->pow==current1->pow){
            head = current1;
            current1->coeff = (current1->coeff+current2->coeff);
            current1 = current1->next;
            current2 = current2->next;
        }else if(current2->pow<current1->pow){
            head = current1;
            current1 = current1->next;
        }else{
            head = current2;
            current2 = current2->next;
        }
        prev = head;
        while(nullptr!=current1 && nullptr!=current2){
            if(current2->pow==current1->pow){
                current1->coeff = (current1->coeff+current2->coeff);
                if(nullptr!=prev)
                    prev->next = current1;
                prev = current1;
                current1 = current1->next;
                current2 = current2->next;
            }else if(current2->pow<current1->pow){
                prev->next = current1;
                Node *temp = current1->next;
                prev = current1;
                current1 = temp;
            }else{
                prev->next = current2;
                Node *temp = current2->next;
                current2->next = current1;
                prev = current2;
                current2 = temp;
            }
        }
        if(nullptr==current1){
            prev->next = current2;
        }else if(nullptr==current2){
            prev->next = current1;
        }
        return head;
    }
};


// { Driver Code Starts.
int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
        struct Node *tail1  = NULL,*tail2 = NULL;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly1,&tail1,x,y);
        }
        
         int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly2,&tail2,x,y);
        }
        Solution obj;
        Node *sum = obj.addPolynomial(poly1,poly2);
        for(Node* ptr=sum ; ptr ; ptr=ptr->next  )
        {
            // printing polynomial
            cout<< ptr->coeff << "x^" << ptr->pow;
            if(ptr->next) cout<<" + ";
        }
        cout<<endl;
       
    }

}
  // } Driver Code Ends