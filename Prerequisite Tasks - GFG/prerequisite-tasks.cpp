//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prq) {
	    vector<int> ind(N,0);
	    vector<int> adj[N];
	    for(auto p : prq){
	        ind[p.first]++;
	        adj[p.second].push_back(p.first);
	    }
	    queue<int> q;
	    for(int i=0;i<N;i++){
	        if(ind[i]==0){
	            q.push(i);
	        }
	    }
	    int count = 0;
	    while(!q.empty()){
	        auto u = q.front(); q.pop();
	        count ++;
	        for(int v : adj[u]){
	            ind[v]--;
	            if(ind[v]==0)
	                q.push(v);
	        }
	    }
	    return count==N;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends