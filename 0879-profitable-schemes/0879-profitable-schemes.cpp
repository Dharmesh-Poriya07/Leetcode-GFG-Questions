class Solution {
    int mod = 1e9+7;
    int dp[101][101][101];
    
    int solve(int index,int selected_members,int curr_profit,int n,int minProfit,vector<int>& group, vector<int>& profit){
        if(group.size()<=index){
            return curr_profit >= minProfit;
        }
        
        if(-1 != dp[index][selected_members][curr_profit]) return dp[index][selected_members][curr_profit];
        
        int not_selected = solve(index+1,selected_members,curr_profit,n,minProfit,group,profit);
        int selected = 0;
        
        if(selected_members+group[index] <= n){
            // curr_profit at most 101, just we need to verify it should be greater than minProfit
            selected = solve(index+1,selected_members+group[index],min(minProfit,profit[index]+curr_profit),n,minProfit,group,profit);
        }
        
        return dp[index][selected_members][curr_profit] = (selected%mod + not_selected%mod)%mod;
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        // first 3 args of solve function are : current_index,current_selected_members,current_profit
        return solve(0,0,0,n,minProfit,group,profit);
    }
};