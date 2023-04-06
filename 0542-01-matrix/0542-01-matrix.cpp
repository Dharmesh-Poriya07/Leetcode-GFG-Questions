class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> ans(rows,vector<int>(cols,-1));
        queue<vector<int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(0==mat[i][j]){
                    q.push({i,j,0});
                    mat[i][j] = 2;
                }
            }
        }
        vector<int> dir[] = {{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            ans[curr[0]][curr[1]] = curr[2];
            
            for(auto d : dir){
	            int nr = d[0]+curr[0];
	            int nc = d[1]+curr[1];
	            if(0<=nr and 0<=nc and nr<rows and nc<cols and 2!=mat[nr][nc]){
	                q.push({nr,nc,1+curr[2]});
	                mat[nr][nc] = 2;
	            }
	        }
        }
        return ans;
    }
};