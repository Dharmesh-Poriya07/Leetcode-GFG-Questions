class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> freq1(26,0),freq2(26,0);
        int l1 = s1.size();
        int l2 = s2.size();
        for(int i=0;i<l1;i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        
        for(int i=0;i<l2-l1;i++){
            if(freq1==freq2) return true;
            freq2[s2[i]-'a']--;
            freq2[s2[i+l1]-'a']++;
        }
        
        return freq1==freq2;
    }
};