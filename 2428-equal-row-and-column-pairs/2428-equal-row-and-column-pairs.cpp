class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        unordered_map<string,int> freq;
        for(int i=0;i<n;i++){
            string row = "";
            for(int j=0;j<n;j++){
                for(char ch : to_string(grid[i][j]))
                    row.push_back(ch);
                row.push_back('#');
            }
            freq[row]++;
        }
        for(int j=0;j<n;j++){
            string col = "";
            for(int i=0;i<n;i++){
                for(char ch : to_string(grid[i][j]))
                    col.push_back(ch);
                col.push_back('#');
            }
            ans += freq[col];
        }
        return ans;
    }
};