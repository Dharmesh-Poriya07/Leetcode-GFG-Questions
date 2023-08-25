class Solution {
private:
    vector<vector<int>> dp;
    int helper(string &s1,string &s2,string &s3,int i,int j){
        if(s1.size()==i && s2.size()==j) return 1;
        
        if(-1!=dp[i][j]) return dp[i][j];
        
        if(s1.size()>i && s1[i]==s3[i+j]){
            dp[i][j] = helper(s1,s2,s3,i+1,j);
            if(1==dp[i][j]){
                return 1;
            }
        }
        
        if(s2.size()>j && s2[j]==s3[i+j]){
            dp[i][j] = helper(s1,s2,s3,i,j+1);
            if(1==dp[i][j]){
                return 1;
            }
        }
        
        return dp[i][j] = 0;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        dp = vector(s1.size()+1,vector<int>(s2.size()+1,-1));
        return helper(s1,s2,s3,0,0);
    }
};