class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> freq,mp;
        for(char ch : t){
            freq[ch]++;
            // mp[ch]++;
        }
        int i=0,j=0;
        int count = 0;
        int mxl = INT_MAX;
        string ans = "";
        
        while(s.size()>j){
            if(0<freq[s[j]]){
                mp[s[j]]++;
                if(mp[s[j]]<=freq[s[j]]){
                    count ++; 
                }
            }
            if(count == t.size()){
                while(s.size()>i and count==t.size()){
                    if(0<freq[s[i]]){
                        if(mp[s[i]]-1 < freq[s[i]])
                            count --;
                        mp[s[i]] --;
                    }
                    if(j-i+1 < mxl){
                        ans = s.substr(i,j-i+1);
                        mxl = j-i+1;
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
        
    }
};