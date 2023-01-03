class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<string> transpose(strs[0].size(),"");
        for(string row : strs){
            int i=0;
            for(char ch : row){
                transpose[i++].push_back(ch);
            }
        }
        int deleted_col = 0;
        for(string col : transpose){
            for(int i=1;i<col.size();i++){
                if(col[i-1]>col[i]){
                    deleted_col ++;
                    break;
                }
            }
        }
        return deleted_col;
    }
};