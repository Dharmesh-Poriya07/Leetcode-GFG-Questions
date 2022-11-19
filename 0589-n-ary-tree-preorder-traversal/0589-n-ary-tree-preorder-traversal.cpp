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
public:
    vector<int> preorder(Node* root) {
        if(nullptr == root) return {};
        
        vector<int> ans;
        ans.push_back(root->val);
        
        for(Node *child : root->children){
            vector<int> subt = preorder(child);
            for(int s : subt)
                ans.push_back(s);
        }
        return ans;
    }
};