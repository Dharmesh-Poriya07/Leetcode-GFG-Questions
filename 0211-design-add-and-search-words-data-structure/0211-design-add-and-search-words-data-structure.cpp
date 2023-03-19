class WordDictionary {
public:
    vector<WordDictionary *> trie;
    bool isEnd;
    WordDictionary() {
        this->trie = vector<WordDictionary *>(26,nullptr);
        this->isEnd = false;
    }
    
    void addWord(string word) {
        WordDictionary *current = this;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(!current->trie[ch-'a']){
                current->trie[ch-'a'] = new WordDictionary();
            }
            current = current->trie[ch-'a'];
        }
        current->isEnd = true;
    }
    bool dfs(WordDictionary *t,string &word,int ind){
        if(!t) return false;
        if(ind==word.size()){
            return t->isEnd;
        } 
        if('.'==word[ind]){
            for(int i=0;i<26;i++){
                if(dfs(t->trie[i],word,ind+1)){
                    return true;
                }
            }
        }else{
            int ch = word[ind]-'a';
        if(t->trie[ch])
            return dfs(t->trie[ch],word,ind+1);
        }
        
        return false;
    }
    bool search(string word) {
        return dfs(this,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */