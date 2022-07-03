// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    vector<string> helper(string &s,int start,set<string> &hs,map<int,vector<string>> &hm){
        if(hm.end()!=hm.find(start)) return hm[start];
        
        vector<string> validsubstr;
        if(start==s.size()) validsubstr.push_back("");
        
        for(int end=start+1;s.size()>=end;end++){
            string prefix = s.substr(start,end-start);
            if(hs.end()!=hs.find(prefix)){
                vector<string> suffixes = helper(s,end,hs,hm);
                for(string suffix : suffixes){
                    validsubstr.push_back(prefix + (suffix==""?"":" ") + suffix);
                }
            }
        }
        hm[start] = validsubstr;
        return validsubstr;
    }
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        set<string> hs(dict.begin(),dict.end());
        map<int,vector<string>> hm;
        return helper(s,0,hs,hm);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends