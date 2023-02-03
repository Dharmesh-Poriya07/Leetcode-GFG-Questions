class Solution {
public:
    string convert(string s, int numRows) {
        if(1==numRows) return s;
        int no_cols = s.size();
        vector<vector<char>> matrix(numRows,vector<char>(no_cols,'#'));
        int i=0;
        for(int j=0;j<s.size() and i<s.size();j++){
            for(int row=0;row<numRows and i<s.size();row++){
                matrix[row][j] = s[i];
                i++;
            }
            j++;
            for(int k=0,row=numRows-2;k<numRows-2 and i<s.size();k++,row--,i++){
                matrix[row][j] = s[i];
                j++;
            }
        }
        string ans = "";
        for(int i=0;i<numRows;i++)
            for(int j=0;j<s.size();j++)
                if(matrix[i][j]!='#') ans.push_back(matrix[i][j]);
            
        return ans;
    }
};