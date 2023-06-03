/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;

        queue<Node *> q;
        q.push(node);
        unordered_map<Node *,Node *> ump;
        ump.insert({node,new Node(node->val)});

        while(!q.empty()){
            auto curr = q.front(); q.pop();

            for(auto &adj : curr->neighbors){
                if(ump.find(adj)==ump.end()){
                    ump.insert({adj,new Node(adj->val)});
                    q.push(adj);
                }
                ump[curr]->neighbors.push_back(ump[adj]);
            }
        }

        return ump[node];
    }
};