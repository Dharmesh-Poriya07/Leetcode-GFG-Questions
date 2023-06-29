/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string treenodes = "";
        queue<TreeNode *> q;
        if(root) q.push(root);

        while(!q.empty()){
            auto curr = q.front(); q.pop();

            if(curr){
                treenodes.append(to_string(curr->val)+",");
            }else{
                treenodes.push_back('#');
                treenodes.push_back(',');
            }
            if(curr){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        cout<<treenodes<<endl;
        return treenodes;
    }
    string getValue(string &data,int &ind){
        string val = "";
        while(ind<data.size() and data[ind]!=','){
            val.push_back(data[ind]);
            ind++;
        }
        ind++;
        return val;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return nullptr;

        queue<TreeNode *> q;
        int index = 0;
        TreeNode *root = new TreeNode(stoi(getValue(data,index)));
        q.push(root);
        while(!q.empty()){
            auto curr = q.front(); q.pop();

            string val = getValue(data,index);
            if("#"==val){
                curr->left = nullptr;
            }else{
                curr->left = new TreeNode(stoi(val));
                q.push(curr->left);
            }

            val = getValue(data,index);
            if("#"==val){
                curr->right = nullptr;
            }else{
                curr->right = new TreeNode(stoi(val));
                q.push(curr->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));