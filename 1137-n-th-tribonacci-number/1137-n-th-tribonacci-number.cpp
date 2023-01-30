class Solution {
public:
    int tribonacci(int n) {
        if(3>n)
            return 1>=n?n:n-1;
        vector<int> values(n+1);
        values[0] = 0;
        values[1] = values[2] = 1;
        for(int i=3;i<=n;i++)
            values[i] = values[i-3]+values[i-2]+values[i-1];
        return values[n];
    }
};