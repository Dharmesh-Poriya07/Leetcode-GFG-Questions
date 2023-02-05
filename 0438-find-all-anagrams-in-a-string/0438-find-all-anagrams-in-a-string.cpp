class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lnp = p.size();
        int lns = s.size();
        vector<int> ans;
        if(lnp>lns) return ans;
        vector<int> freq1(26,0),freq2(26,0);
        for(int i=0;i<lnp;i++){
            freq1[p[i]-'a']++;
            freq2[s[i]-'a']++;
        }
        for(int i=lnp;i<lns;i++){
            if(freq1==freq2) ans.push_back(i-lnp);
            freq2[s[i-lnp]-'a']--;
            freq2[s[i]-'a']++;
        }
        if(freq1==freq2) ans.push_back(lns-lnp);
        return ans;
    }
};