class Trie {
public:
    vector<Trie *> trie;
    bool isEnding;
    Trie() {
        this->trie = vector<Trie *>(26,nullptr);
        this->isEnding = false;
    }
    
    void insert(string word) {
        Trie *current = this;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(!current->trie[ch-'a'])
                current->trie[ch-'a'] = new Trie();
            current = current->trie[ch-'a'];
        }
        current->isEnding = true;
    }
    
    bool search(string word) {
        Trie *current = this;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(!current->trie[ch-'a'])
                return false;
            current = current->trie[ch-'a'];
        }
        return current->isEnding;
    }
    
    bool startsWith(string prefix) {
        Trie *current = this;
        for(int i=0;i<prefix.size();i++){
            char ch = prefix[i];
            if(!current->trie[ch-'a'])
                return false;
            current = current->trie[ch-'a'];
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