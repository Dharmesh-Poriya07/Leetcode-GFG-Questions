static int MOD=1e9+7;
class Solution {
public:
    vector<vector<vector<int>>> memo;
    vector<vector<int>> prefixSum;
    int getApples(int row1,int col1,int row2,int col2) 
        
    {
        return prefixSum[row2+1][col2+1]-prefixSum[row1][col2+1]-prefixSum[row2+1][col1]+prefixSum[row1][col1];
    }
    int dp(vector<string>& pizza,int left,int top,int k)
    {
        if(memo[top][left][k]!=-1)
            return memo[top][left][k];
        if(k==1)
            return getApples(top,left,pizza.size()-1,pizza[0].size()-1)!=0;    
        
        memo[top][left][k]=0;
        for(int c=left;c<pizza[0].size()-1;c++)    
            
            if(getApples(top,left,pizza.size()-1,c))    
                
               memo[top][left][k]=(memo[top][left][k]+dp(pizza,c+1,top,k-1))%MOD;  
        for(int r=top;r<pizza.size()-1;r++)        
            
            if(getApples(top,left,r,pizza[0].size()-1)) 
                
                memo[top][left][k]=(memo[top][left][k]+dp(pizza,left,r+1,k-1))%MOD;
        return memo[top][left][k];
    }
    int ways(vector<string>& pizza, int k) 
    {
        memo.resize(pizza.size(),vector<vector<int>>(pizza[0].size(),vector<int>(k+1,-1)));
        prefixSum.resize(pizza.size()+1,vector<int>(pizza[0].size()+1,0));      
        
        for(int i=0;i<pizza.size();i++)
            for(int j=0;j<pizza[0].size();j++)
                prefixSum[i+1][j+1]=prefixSum[i+1][j]+prefixSum[i][j+1]-prefixSum[i][j]+(pizza[i][j]=='A');
        return dp(pizza,0,0,k);
    }
};