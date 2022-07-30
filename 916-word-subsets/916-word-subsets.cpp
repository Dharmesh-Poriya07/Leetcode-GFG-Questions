class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        
        vector<unordered_map<char,int>> vf;
        for(string w1 : words1){
            unordered_map<char,int> mp;
            for(char ch : w1){
                mp[ch] ++;
            }
            vf.push_back(mp);
        }
        // for(int i=0;vf.size()>i;i++){
        //     unordered_map<char,int> temp;
        //     for(auto it : vf[i]){
        //         temp[it.first] += words2.size();
        //     }
        //     vf[i] = temp;
        // }
        map<char,int> w2f;
        for(string w2 : words2){
            map<char,int> t;
            for(char ch : w2){
                t[ch] ++;
                w2f[ch] = max(w2f[ch],t[ch]);
            }
        }
        int i=0;
        for(auto m : vf){
            bool flag = true;
            for(auto it : w2f){
                if(it.second>m[it.first]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans.push_back(words1[i]);
            }
            i++;
        }
        return ans;
    }
};