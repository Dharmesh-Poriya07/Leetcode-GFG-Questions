class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string,vector<pair<string,string>>> mp;
        
        for(string s : paths){
            string path = "";
            int n = s.size();
            int i=0;
            while(i!=n and ' '!=s[i]){
                path.push_back(s[i]);
                i++;
            }
            i++;
            vector<pair<string,string>> files;
            while(i<n){
                string fname = "";
                string content = "";
                while(i<n and '('!=s[i]){
                    fname.push_back(s[i]);
                    i++;
                }
                i ++;
                while(i<n and ')'!=s[i]){
                    content.push_back(s[i]);
                    i++;
                }
                i += 2;
                files.push_back({fname,content});
            }
            for(auto it : files){
                mp[it.second].push_back({path,it.first});
            }
        }
        
        vector<vector<string>> ans;
        
        for(auto it : mp){
            if(1<it.second.size()){
                vector<string> sameFiles;
                for(auto files : it.second){
                    string path = files.first +"/"+ files.second;
                    sameFiles.push_back(path);
                }
                ans.push_back(sameFiles);
            }
        }
        return ans;
    }
};