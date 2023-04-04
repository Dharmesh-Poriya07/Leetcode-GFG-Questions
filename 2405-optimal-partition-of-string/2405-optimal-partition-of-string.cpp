class Solution {
public:
    int partitionString(string s) {
        int count_ans = 0;
        for(int i=0;i<s.size();){
            vector<int> freq(26,0);
            count_ans ++;
            while(s.size()>i and 0==freq[s[i]-'a']){
                freq[s[i]-'a']++;
                i++;
            }
        }
        return count_ans;
    }
};