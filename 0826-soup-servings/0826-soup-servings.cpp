class Solution {
public:
    map<pair<int,int>,double> dp;
    double solve(int a,int b){
        if(a<=0 and b<=0) return 0.5;
        if(a<=0) return 1;
        if(b<=0) return 0;
        
        if(dp.count({a,b})) return dp[{a,b}];

        double op1 = solve(a-100,b);
        double op2 = solve(a-75,b-25);
        double op3 = solve(a-50,b-50);
        double op4 = solve(a-25,b-75);
        double res = (op1+op2+op3+op4)/4.0;
        dp[{a,b}] = res;
        return res;
    }
    double soupServings(int n) {
        if(5000<=n) return 1;
        return solve(n,n);
    }
};