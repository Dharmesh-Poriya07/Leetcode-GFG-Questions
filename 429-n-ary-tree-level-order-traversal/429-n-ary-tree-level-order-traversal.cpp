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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node *> q;
        vector<vector<int>> lt;
        if(nullptr!=root){
            q.push(root);
        }
        while(!q.empty()){
            int sz = q.size();
            vector<int> level;
            while(sz--){
                Node *current = q.front();
                q.pop();
                level.push_back(current->val);
                for(Node *child : current->children){
                    if(nullptr!=child)
                        q.push(child);
                }
            }
            lt.push_back(level);
        }
        return lt;
    }
};