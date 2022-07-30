class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        
        vector<vector<int>> vf(words1.size(),vector<int>(26,0));
        for(int i=0;words1.size()>i;i++){
            for(char ch : words1[i]){
                vf[i][ch-'a']++;
            }
        }
        vector<int> singlewords2(26,0);
        for(string w2 : words2){
            vector<int> freq(26,0);
            for(char ch : w2){
                freq[ch-'a'] ++;
                singlewords2[ch-'a'] = max(singlewords2[ch-'a'],freq[ch-'a']);
            }
        }
        for(int i=0;vf.size()>i;i++){
            bool flag = true;
            for(int j=0;26>j;j++){
                if(singlewords2[j]>vf[i][j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};