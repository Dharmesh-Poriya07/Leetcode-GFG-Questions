//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int curr_pixel = image[sr][sc];
        image[sr][sc] = color;
        vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            // image[curr.first][curr.second] = color;
            for(auto d : dir){
                int r = curr.first+d[0];
                int c = curr.second+d[1];
                if(image.size()>r and image[0].size()>c and -1<r and -1<c and image[r][c]==curr_pixel){
                    image[r][c] = color;
                    q.push({r,c});
                }
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends