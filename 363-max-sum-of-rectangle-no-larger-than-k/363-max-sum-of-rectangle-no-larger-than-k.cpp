class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int maxSum = INT_MIN;
        
        for(int l = 0; l < n; l++) {
            vector<int> sumArr(m, 0);
            for(int r = l; r < n; r++) {
                for(int i = 0; i < m; i++) sumArr[i] += matrix[i][r];
                for(int i = 0; i < m; i++) {
                    int sum = 0;
                    for(int j = i; j < m; j++) {
                        sum += sumArr[j];
                        if(sum > maxSum && sum <= k) maxSum = sum;
                    }
                }
            }
        }
        return maxSum;
    }
};