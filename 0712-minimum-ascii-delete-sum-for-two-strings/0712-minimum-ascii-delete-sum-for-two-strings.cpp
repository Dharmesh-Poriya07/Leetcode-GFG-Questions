class Solution {
public:
    int dp[1001][1001];
    int remains(string s , int i){
        int count = 0;
        for(int j = i ; j < s.size() ; j++){
            count += s[j];
        }
        return count;
    }
    int solve(int i , int j , string& s1 , string& s2){
        if(i == s1.size() && j == s2.size()) return 0;
        // all remaining character must be deleted
        if(i == s1.size() && j < s2.size()) return remains(s2 , j);
        if(j == s2.size() && i < s1.size()) return remains(s1 , i);
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] = solve(i + 1 , j + 1 , s1 , s2);
        }
        else{
            return dp[i][j] = min({s1[i]+ solve(i + 1 , j , s1 , s2) ,
                                s2[j] + solve(i , j + 1 , s1 ,s2) ,});
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        // modification of lcs
        return solve(0 , 0 , s1 , s2);
    }
};