class Solution {
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
    vector<string> wordBreak(string s, vector<string>& dict) {
        set<string> hs(dict.begin(),dict.end());
        map<int,vector<string>> hm;
        return helper(s,0,hs,hm);
    }
};