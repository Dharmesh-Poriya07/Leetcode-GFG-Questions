/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    private:
    vector<int> ans;
    void helper(Node *root){
        if(nullptr == root) return;
        
        
        for(Node *child : root->children){
            helper(child);
        }
        ans.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        ans = vector<int>();
        helper(root);
        return ans;
    }
};