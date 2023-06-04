class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> f;
        string curr = "";
        for(int j=9,i=0;j<s.size();j++,i++){
            curr = "";
            for(int k=i;k<=j;k++) curr.push_back(s[k]);
            f[curr]++;
        }
        vector<string> ans;
        for(auto it : f){
            if(it.second>1)
                ans.push_back(it.first);
        }
        return ans;
    }
};