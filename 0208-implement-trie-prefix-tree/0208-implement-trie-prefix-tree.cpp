class Node {
    private:
    Node *keys[26];
    bool flag;

    public:
    bool isContainsKey(char ch){
        return keys[ch-'a']!=nullptr;
    }
    void putKey(char ch){
        keys[ch-'a'] = new Node();
    }
    Node *moveNext(char ch){
        return keys[ch-'a'];
    }
    void setFlag(){
        flag = true;
    }
    bool getFlag(){
        return flag;
    }
};
class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(char ch : word){
            if(!node->isContainsKey(ch)){
                node->putKey(ch);
            }
            node = node->moveNext(ch);
        }
        node->setFlag();
    }
    
    bool search(string word) {
        Node *node = root;
        for(char ch : word){
            if(!node->isContainsKey(ch)){
                return false;
            }
            node = node->moveNext(ch);
        }
        return node->getFlag();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(char ch : prefix){
            if(!node->isContainsKey(ch)){
                return false;
            }
            node = node->moveNext(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */