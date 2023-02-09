class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> st;
        for(auto &i : ideas)
            st.insert(i);
        
        vector<vector<int>> dp(26,vector<int>(26,0));
        for(int i=0;i<ideas.size();i++){
            char ch1 = ideas[i][0];
            for(int j=0;j<26;j++){
                char ch2 = j+'a';
                ideas[i][0] = ch2;
                if(st.end()==st.find(ideas[i])){
                    dp[ch1-'a'][j]++;
                }
            }
        }
        long long int ans = 0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                ans += (dp[i][j]*dp[j][i]);
            }
        }
        return ans;
    }
};