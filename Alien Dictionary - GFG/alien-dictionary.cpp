//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string topoSort(int V, vector<int> adj[]) 
	{
	    string toposort;
	    vector<int> indegree(V,0);
	    for(int u=0;u<V;u++)
	        for(int v : adj[u])
	            indegree[v]++;
	    
	    queue<int> q;
	    for(int u=0;u<V;u++)
	        if(0==indegree[u])
	            q.push(u);
	            
	   while(!q.empty()){
	       auto u = q.front(); q.pop();
	       toposort.push_back('a'+u);
	       for(int v : adj[u]){
	           indegree[v]--;
	           if(0==indegree[v])
	               q.push(v);
	       }
	   }
	   return toposort;
	}
    string findOrder(string dict[], int N, int K) {
        vector<int> graph[K];
        
        for(int i=1;i<N;i++){
            string s1,s2;
            s1 = dict[i-1];
            s2 = dict[i];
            int t1 = s1.size();
            int t2 = s2.size();
            int j1=0, j2=0;
            while(j1<t1 and j2<t2 and s1[j1]==s2[j2]){
                j1++;
                j2++;
            }
            if(j1<t1 and j2<t2){
                graph[s1[j1]-'a'].push_back(s2[j2]-'a');
            }
        }
        
        return topoSort(K,graph);
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends