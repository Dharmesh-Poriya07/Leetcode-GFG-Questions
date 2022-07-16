class Solution {
private:
    vector<vector<vector<int>>> dp;
    int M = 1000000007;
    int helper(int m, int n, int maxMove, int startRow, int startColumn){
        if(-1==startRow || -1==startColumn || startRow==m || startColumn==n){
            return 1;
        }
        if(0==maxMove) return 0;
        if(-1!=dp[startRow][startColumn][maxMove]) return dp[startRow][startColumn][maxMove];
        
        int left = helper(m,n,maxMove-1,startRow,startColumn-1);
        int top = helper(m,n,maxMove-1,startRow-1,startColumn);
        int right = helper(m,n,maxMove-1,startRow,startColumn+1);
        int bottom = helper(m,n,maxMove-1,startRow+1,startColumn);
        
        return dp[startRow][startColumn][maxMove] = (((left%M)+(top%M))%M+((right%M)+(bottom%M))%M)%M;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp = vector(m+1,vector(n+1,vector<int>(maxMove+1,-1)));
        return helper(m,n,maxMove,startRow,startColumn);
    }
};