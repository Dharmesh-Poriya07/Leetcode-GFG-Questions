// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    int helper(vector<vector<int>> &graph,int s,int d){
        if(s==d) return 1;
        int count = 0;
        for(auto adj : graph[s]){
                count += helper(graph,adj,d);
        }
        return count;
    }
public:
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    vector<vector<int>> graph(n);
	    for(auto v : edges){
	        graph[v[0]].push_back(v[1]);
	    }
	    return helper(graph,s,d);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends