class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;
        vector<int> freq1(26,0),freq2(26,0);
        for(int i=0;i<word1.size();i++){
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(0==freq1[i] or freq1[i]==freq2[i]) continue;
            if(0==freq2[i]) return false;
            bool flag = false;
            for(int j=i+1;j<26;j++){
                if(freq2[j]==freq1[i]){
                    flag = true;
                    swap(freq2[i],freq2[j]);
                    break;
                }
            }
            if(false==flag) return false;
        }
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]) return false;
        }
        return true;
    }
};