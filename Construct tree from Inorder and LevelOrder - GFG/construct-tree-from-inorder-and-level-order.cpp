//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/
unordered_map<int,int> m;
unordered_map<int,int> indexs;
Node *helper(int inorder[],int levelorder[],int n,int istart,int iend){
    if(istart>iend) return NULL;
    
    int inIndex = istart;
    for(int i=istart+1;i<=iend;i++){
        if(m[inorder[inIndex]] > m[inorder[i]])
            inIndex = i;
    }
    Node *root = new Node(inorder[inIndex]);
    if(istart == iend) return root;
    
    root->left = helper(inorder,levelorder,n,istart,inIndex-1);
    root->right = helper(inorder,levelorder,n,inIndex+1,iend);
    return root;
}

Node* buildTree(int inorder[], int levelorder[], int iStart, int iEnd,int n)
{
    for(int i=0;i<n;i++){
      m[levelorder[i]] = i;
      indexs[inorder[i]] = i;
    }
        
    return helper(inorder,levelorder,n,0,n-1);
}