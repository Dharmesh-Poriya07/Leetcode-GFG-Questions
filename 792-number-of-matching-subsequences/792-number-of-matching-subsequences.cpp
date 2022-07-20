class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans  = 0;
        sort(words.begin(),words.end());
        string prev = "";
        bool istrue = false;
        int n=s.size();
        for(string word : words){
            if(prev==word){
                ans += istrue?1:0;
                continue;
            }
            int i,j,w;
            i=j=0,w=word.size();
            while(i<n && j<w){
                if(s[i]==word[j]){
                    j++,i++;
                }else{
                    i++;
                }
            }
            if(j==w){
                ans ++;
                istrue = true;
            }else{
                istrue = false;
            }
            
            prev = word;
        }
        return ans;
    }
};