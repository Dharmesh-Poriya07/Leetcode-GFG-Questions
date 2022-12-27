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
    string tree2str(TreeNode* root) {
        if(nullptr==root)
            return "";
        string ans = "",left="",right="";
        ans = to_string(root->val);
        
        if(nullptr!=root->left){
            left.push_back('(');
            for(char ch : tree2str(root->left)) left.push_back(ch);
            left.push_back(')');
        }else if(nullptr!=root->right){
            left.push_back('(');
            left.push_back(')');
        }
        
        if(nullptr!=root->right){
            right.push_back('(');
            for(char ch : tree2str(root->right)) right.push_back(ch);
            right.push_back(')');
        }
        
        return ans+left+right;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return tree2str(root);
    }
    
    vector<int> getNumber(string &s,int ind){
        bool ngve = false;
        if('-'==s[ind]){
            ngve = true;
            ind++;
        }
        int num = 0;
        while(ind<s.size() and '(' != s[ind] and ')'!=s[ind]){
            num *= 10;
            num += (s[ind]-'0');
            ind++;
        }
        if(ngve){
            num *= -1;
        }
        return {num,ind};
    }
    pair<string,int> sub(string &s,int ind){
        string stree = "";
        int count = 1;
        ind++;
        while(ind<s.size() and 0!=count){
            if(')' == s[ind]) count--;
            else if('('==s[ind]) count++;
            stree.push_back(s[ind]);
            ind++;
        }
        if(stree.size()>0)
            stree.pop_back();
        return {stree,ind};
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data,int ind=0) {
        if(data == "" or ind>=data.size()) return nullptr;
        auto root_data = getNumber(data,ind);
        TreeNode *root = new TreeNode(root_data[0]);
        auto leftsub = sub(data,root_data[1]);
        root->left = deserialize(leftsub.first);
        auto rightsub = sub(data,leftsub.second);
        root->right = deserialize(rightsub.first);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));