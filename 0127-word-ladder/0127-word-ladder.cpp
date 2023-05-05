class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> s(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        s.erase(beginWord);
        
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            string word = curr.first;
            int steps = curr.second;
            if(word == endWord) return steps;
            for(int i=0;i<word.size();i++){
                char c = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i] = ch;
                    if(s.find(word) != s.end()){
                        s.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = c;
            }
        }
        return 0;
    }
};