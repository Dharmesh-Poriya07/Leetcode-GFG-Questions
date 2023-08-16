class Solution {
private:
    vector<vector<int>> dp;
    int helper(int row,int col,int m,int n){
        if(row==m or col==n) return 0;
        if(row==m-1 && col==n-1) return 1;
        if(-1!=dp[row][col]) return dp[row][col];
        int right = helper(row,col+1,m,n);
        int bottom = helper(row+1,col,m,n);
        return dp[row][col] = right+bottom;
    }
public:
    int uniquePaths(int m, int n) {
        dp = vector(m+1,vector(n+1,-1));
        return helper(0,0,m,n);
    }
};