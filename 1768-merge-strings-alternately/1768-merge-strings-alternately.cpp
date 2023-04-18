class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n,m,i,j;
        string ans = "";
        n = word1.size(), m=word2.size();
        i = j = 0;
        while(i<n or j<m){
            if(i<n) ans.push_back(word1[i++]);
            if(j<m) ans.push_back(word2[j++]);
        }
        return ans;
    }
};