class TrieNode {
    public:
    vector<TrieNode *> children;
    bool isWordEnd;
    TrieNode(){
        this->children = vector<TrieNode *>(26,nullptr);
        this->isWordEnd = false;
    }
};


class WordDictionary {
private:
    TrieNode *root;
public:
    
    WordDictionary() {
        this->root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *current = this->root;
        for(char ch : word){
            if(!current->children[ch-'a']){
                current->children[ch-'a'] = new TrieNode();
            }
            current = current->children[ch-'a'];
        }
        current->isWordEnd = true;
    }
    bool dfs(TrieNode *trie,string &word,int ind){
        if(!trie) return false;
        if(ind==word.size()){
            return trie->isWordEnd;
        } 
        if('.'==word[ind]){
            for(int i=0;i<26;i++){
                if(dfs(trie->children[i],word,ind+1)){
                    return true;
                }
            }
        }else{
            int ch = word[ind]-'a';
            if(trie->children[ch])
                return dfs(trie->children[ch],word,ind+1);
        }
        
        return false;
    }
    bool search(string word) {
        return dfs(this->root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */