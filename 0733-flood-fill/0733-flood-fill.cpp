class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int curr_pixel = image[sr][sc];
        vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            image[curr.first][curr.second] = color;
            for(auto d : dir){
                int r = curr.first+d[0];
                int c = curr.second+d[1];
                if(image.size()>r and image[0].size()>c and -1<r and -1<c and image[r][c]==curr_pixel){
                    q.push({r,c});
                }
            }
        }
        return image;
    }
};