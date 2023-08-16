class Solution {
private:
    vector<vector<int>> dp;
    int recursive(vector<vector<int>>& triangle,int row,int col){
        if(triangle.size()-1==row) return triangle[row][col];
        
        if(-1!=dp[row][col]) return dp[row][col];
        
        int left = recursive(triangle,row+1,col);
        int right = recursive(triangle,row+1,col+1);
        dp[row][col] = triangle[row][col] + min(left,right);
        return dp[row][col];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        dp.resize(0,vector<int>(0));
        for(vector<int> r : triangle){
            dp.push_back(vector<int>(r.size(),-1));
        }
        int ans = recursive(triangle,0,0);
        return ans;
    }
};